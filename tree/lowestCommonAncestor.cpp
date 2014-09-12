```c++
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

TreeNode* deSerializePreOrder(vector<string>& values, int& start) {
  if (start >= values.size()) return NULL;
  string val = values[start++];
  if (val == "#") return NULL;
  TreeNode* root = new TreeNode(atoi(val.c_str()));
  root->left = deSerializePreOrder(values, start);
  root->right = deSerializePreOrder(values, start);
  return root;
}

TreeNode* deSerialize(istream& ins) {
  string word, line;
  vector<string> words;
  getline(ins, line);
  istringstream iss(line);
  while (!iss.eof()) {
	iss >> word;
    words.push_back(word);
  }
  int start = 0, last = (int)words.size() - 1;
  return deSerializePreOrder(words, start);
  //return deSerializePostOrder(words, last);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2, int& covered) {
  covered = 0;
  if (!root) return NULL;
  if (root == n1 || root == n2) covered = 1;
  int lCovered = 0, rCovered = 0;
  TreeNode* lCommon = lowestCommonAncestor(root->left, n1, n2, lCovered);
  if (lCommon) return lCommon;
  TreeNode* rCommon = lowestCommonAncestor(root->right, n1, n2, rCovered);
  if (rCommon) return rCommon;
  covered += lCovered + rCovered;
  if (covered == 2) return root;
  else return NULL;
}

TreeNode* getNode(TreeNode* root, int val) {
	if (!root) return NULL;
	if (root->val == val) return root;
	TreeNode* ret = NULL;
	ret = getNode(root->left, val);
	if (ret) return ret;
	ret = getNode(root->right, val);
	if (ret) return ret;
	return NULL;
}

int main(int argc, _TCHAR* argv[])
{
	TreeNode* root = deSerialize(cin);
	int a, b, covered;
	cin >> a;
	cin >> b;
	TreeNode* ret = lowestCommonAncestor(root, getNode(root, a), getNode(root, b), covered);
	return 0;
}
```


