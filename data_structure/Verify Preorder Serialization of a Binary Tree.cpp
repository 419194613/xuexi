331. Verify Preorder Serialization of a Binary Tree
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false


class Solution {
public: void DFS(vector<string>& str, int& index, int& flag)
    {
        if(str[index++]=="#") return;
        if(index+1 >= str.size()) {flag = 0; return;}
        DFS(str, index, flag);
        DFS(str, index, flag);
    }
    bool isValidSerialization(string preorder) {
        if(preorder.size()==0) return false;
        preorder += ",";
        vector<string> vec;
        int index = 0, i =0, flag=1;
        while(i < preorder.size())
        {
            int pos = preorder.find(',', i);
            vec.push_back(preorder.substr(i, pos-i));
            i = pos+1;
        }
        DFS(vec, index, flag);
        return flag==0?false:index==vec.size();
    }
}; 

