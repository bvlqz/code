#include <iostream>
#include <string>

class HashNode {
    HashNode* nextNodePtr;
    std::string nodeKey;
    int nodeValue;

public:
    HashNode(std::string key, int value)
    {
        nodeKey = key;
        nodeValue = value;
        nextNodePtr = nullptr;
    }
    ~HashNode(){
        if (this->nextNodePtr != nullptr) delete this->nextNodePtr;
    }
    int getNodeValue() {
        return nodeValue;
    }
    void AppendToTail(const char* key, int value)
    {
        HashNode* newEndNode = new HashNode(key, value);
        HashNode* currentWorkingNode = this;
        while (currentWorkingNode->nextNodePtr != nullptr)
        {
            currentWorkingNode = currentWorkingNode->nextNodePtr;
        }
        currentWorkingNode->nextNodePtr = newEndNode;
    }
};

class HashTable {
public:
    HashTable(int size) {
        tableSize = size;
        list = new HashNode *[size];
    }
    
    void add(std::string k, int v) {
        std::cout << hash(k) << std::endl;
        list[hash(k)] = new HashNode(k, v);
    }
    
    int get(std::string k) {
        return list[hash(k)]->getNodeValue();
    }
    
private:
    int hash(std::string key)
    {
        int keyASCIISum = 0;
        for (int i = 0; i < key.length(); i++){
            keyASCIISum += key[i] + 1;
        }
        return keyASCIISum % tableSize;
    }
    
    HashNode** list;
    int tableSize;
    int itemCount;
};

int main()
{
    std::cout << "Hash Table Example" << std::endl;
    
    HashTable hashTable(2);
    hashTable.add("one", 1);
    hashTable.add("two", 2);
    hashTable.add("yes", 3);
    
    std::cout << "Get Values" <<std::endl;
    std::cout << hashTable.get("yes") << std::endl;
}
