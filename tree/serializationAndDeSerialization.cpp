````c++
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

TreeNode* deSerializePostOrder(vector<string>& values, int& last) {
  if (last < 0 || last >= values.size()) return NULL;
  string val = values[last--];
  if (val == "#") return NULL;
  TreeNode* root = new TreeNode(atoi(val.c_str()));
  root->right = deSerializePostOrder(values, last);
  root->left = deSerializePostOrder(values, last);
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
  //return deSerializePreOrder(words, start);
  return deSerializePostOrder(words, last);
}

int main(int argc, _TCHAR* argv[])
{
	TreeNode* root = deSerialize(cin);
	return 0;
}
````
