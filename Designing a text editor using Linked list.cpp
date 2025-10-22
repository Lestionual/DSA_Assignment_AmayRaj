// https://leetcode.com/problems/design-a-text-editor/?envType=problem-list-v2&envId=linked-list
//Q2. 
class TextEditor 
{
private: 
    stack<char> left,right;
    // Helper: get last up to 10 chars from left stack as a string
    string getLast10() 
    {
        string result;
        vector<char>temp;
    // Extract up to 10 chars from left stack
        for (int i=0; i<10 && !left.empty(); i++) 
        {
            temp.push_back(left.top());
            left.pop();
        }
    // Restore them back into left stack
        for (int i=temp.size()-1; i>=0;i--)
        {
            result.push_back(temp[i]);
            left.push(temp[i]);
        }
        return result;
    }
public:
TextEditor() {}
    // Add text at the cursor position
    void addText(string text) 
    {
        for (char c:text)
            left.push(c);
    }
    // Delete up to k characters to the left of the cursor
    int deleteText(int k) 
    {
        int count=0;
        while (k-->0 && !left.empty()) 
        {
            left.pop();
            count++;
        }
        return count;
    }
    // Move cursor k steps left
    string cursorLeft(int k) 
    {
        while (k-->0 && !left.empty()) 
        {
            right.push(left.top());
            left.pop();
        }
        return getLast10();
    }
    // Move cursor k steps right
    string cursorRight(int k) 
    {
        while (k-->0 && !right.empty()) 
        {
            left.push(right.top());
            right.pop();
        }
        return getLast10();
    }
};
//The code asks for a text editor with the help of using linked list 
//data structure. I handled the problem using stacks and implementing fundamentals
//of linked lists. stacks 'left' and 'right' denoted the side of the cursor
//and the elements on each side of the cursor. since on adding text the text
//always gets appended on the right side hence the text was pushed into the
//right stack. upon deletion the stack on the left loses the text value 
//hence left.pop() was executed. here, k is the number of elements to be
//deleted from the line of texts.