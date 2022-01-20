class Node{
private:
    Node* nextNode;
    char value;

public: 
    Node(char c)
    {
        value = c; 
        nextNode = nullptr; 
    }

    void setNextNode(Node* n) {this->nextNode = n; }
    Node* getNextNode() { return this->nextNode; }
    char getNodeValue() { return this->value; }
};

class Stack{
private:
    Node* top; 
    int size;

public:
    Stack(char start)
    {
        top = new Node(start);
        size = 1; 
    }

    void push(char c)
    { 
        Node* newNode = new Node(c);
        newNode->setNextNode(top);
        top = newNode; 
        size++;
    }

    void pop()
    {
        Node* nextTopNode = top->getNextNode();
        delete top;
        top = nextTopNode;
        size--;
    }

    char peek(){ return top->getNodeValue(); }
    int getSize() {return size; }
};

class Solution {
public:
    bool isValid(std::string s) {
        // get the first character of the string to initialize the stack
        Stack stack(s.at(0));

        // Iterate over the rest of the string
        for (int i = 1; i < s.length(); ++i)
        {
            // if opening bracket, add to stack 
            char currentBracket = s.at(i);
            if (currentBracket == '(' || currentBracket == '[' || currentBracket == '{') {
                stack.push(currentBracket);
            } else {
                // else, if closing bracket, check the top of the stack
                if (stack.getSize() == 0) return false; 

                char topBracket = stack.peek();

                // if the top of the stack matches the opening and closing bracket, pop() the stack
                if (')' == currentBracket && '(' == topBracket) { stack.pop(); }
                else if (']' == currentBracket && '[' == topBracket) { stack.pop(); }
                else if ('}' == currentBracket && '{' == topBracket) { stack.pop(); }
                // if the top of the stack does not match the closing bracket, return false
                else { return false; }
            }
        }
        return (stack.getSize() == 0);
    }
};
