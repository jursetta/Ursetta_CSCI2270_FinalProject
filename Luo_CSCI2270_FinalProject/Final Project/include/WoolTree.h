#ifndef WOOLTREE_H
#define WOOLTREE_H
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <ostream>
#include <deque>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

struct WoolNode
{
    int ranking;
    std::string type;
    int quantity;
    int clean_weight;
    int micron;
    int hauteur_meter;
    WoolNode *parent;
    WoolNode *leftChild;
    WoolNode *rightChild;
    WoolNode() {};
    
    WoolNode(std::string in_type,int in_quantity,int in_clean_weight,int in_micron,int in_hauteur_meter)
    {
        type = in_type;
        quantity = in_quantity;
        clean_weight = in_clean_weight;
        micron = in_micron;
        hauteur_meter=in_hauteur_meter;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
    
};

class WoolTree
{
    
public:
    WoolTree();
    ~WoolTree();
    void printWoolInventory();
    void printWoolpostorder();
    int countWoolNodes();
    void deleteWoolNode(std::string title);
    void addWoolNode(std::string type,int quantity,int clean_weight,int micron,int hauteur_meter);
    void findWool(std::string title);
    void rentWool(std::string title);
    void insertfile(std::string filename);
    void minDepth();
    void maxDepth();
    void mirror(WoolNode * node);
    void printLevelOrder();
    bool treeBuilt();
    
protected:
    
private:
    void DeleteAll(WoolNode * node); //use this for the post-order traversal deletion of the tree
    void printWoolInventory(WoolNode * node);
    int minDepth(WoolNode * node);
    int maxDepth(WoolNode * node);
    int countWoolNodes(WoolNode *node);
    WoolNode* search(std::string title);
    WoolNode* treeMinimum(WoolNode *node);
    WoolNode* leftMost(WoolNode *node);
    WoolNode *root;
    void printWoolpostorder(WoolNode * node);
    void printLevelOrder(WoolNode *node);
};
#endif // WoolTREE_H
