#include "WoolTree.h"
#include <tgmath.h>
using namespace std;

WoolTree::WoolTree()
{
    //ctor
    root=NULL;
}

WoolTree::~WoolTree()
{
    //dtor
    if (treeBuilt()){
    DeleteAll(root);
    }
}


void WoolTree::printWoolInventory(WoolNode* node)
{
    if(node->leftChild!=NULL)
    {
        printWoolInventory(node->leftChild);
    }
    
    cout<<"Wool: "<<node->type<<"Quantity: "<<node->quantity<<"Clean_weight: "<<node->clean_weight<<" Micron: "<<node->micron<<"Hauteur meter: "<<node->hauteur_meter<<endl;
    if(node->rightChild!=NULL)
    {
        printWoolInventory(node->rightChild);
    }
}


void WoolTree::printWoolInventory()
{
    printWoolInventory(root);
    if(root==NULL)
    {
        cout<<"please enter some data"<<endl;
    }
}

void WoolTree::findWool(std::string type)
{
    WoolNode *node=root;
    while(node!=NULL)
    {
        if(node->type.compare(type)<0)
        {
            node=node->rightChild;
        }
        else if(node->type.compare(type)>0)
        {
            node=node->leftChild;
        }
        else
        {
            cout << "Wool Info:" << endl;
            cout << "===========" << endl;
            cout << "Type:" <<node-> type<< endl;
            cout << "Quantity:" << node->quantity << endl;  //?
            cout << "Clean weight:" << node->clean_weight << endl;
            cout << "Micron:" << node->micron << endl;
            cout << "Hauteur meter"<<node->hauteur_meter<<endl;
            node->quantity=node->quantity;
            return;
        }
    }
    cout<< "Wool not found." <<endl;
}


void WoolTree::addWoolNode(std::string type,int quantity,int clean_weight,int micron,int hauteur_meter)
{
    WoolNode* tmp =new WoolNode(type,quantity,clean_weight,micron,hauteur_meter);
    tmp->leftChild=NULL;
    tmp->rightChild=NULL;
    tmp->parent=NULL;
    WoolNode* current=root;
    WoolNode* parent=NULL;
    //search
    while(current!=NULL)
    {
        parent=current;
        if(current->type.compare(tmp->type)>0)
        {
            current = current-> leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
    if(parent==NULL)
    {
        root=tmp;
    }
    else if(parent->type.compare(tmp->type)<0)
    {
        parent->rightChild=tmp;
        tmp->parent=parent;
        // cout << "inserted: " <<value << " left child of: " << parent->key<<endl;
    }
    else
    {
        parent->leftChild=tmp;
        tmp->parent=parent;
        // cout << "inserted: " << tmp->key << " right child of: " << parent->key <<endl;
    }
}


void WoolTree::rentWool(std::string type)
{
    WoolNode *node=root;
    while(node!=NULL)
    {
        if(node->type.compare(type)>0)
        {
            node=node->leftChild;
        }
        else if(node->type.compare(type)<0)
        {
            node=node->rightChild;
        }
        
        else
        {
            node->quantity--;
            cout << "Wool has been rented." << endl;
            cout << "Wool Info:" << endl;
            cout << "===========" << endl;
            cout << "Type:" << node->type << endl;
            cout << "Quantity:" << node->quantity << endl;
            cout << "Clean weight:" << node->clean_weight << endl;
            cout << "Micron:" << node->micron << endl;
            cout << "Hauteur meter:" << node->hauteur_meter<< endl;
            if(node->quantity==0)
            {
                deleteWoolNode(node->type);
            }
            return;
        }
    }
    cout<< "Wool not found." <<endl;
}


int WoolTree::countWoolNodes(WoolNode *node)
{
    int c=0;
    //while(node->rightChild!=NULL&&node->leftChild!=NULL){
    if(node->leftChild!=NULL)
    {
        c+=countWoolNodes(node->leftChild);//left
        
    }
    c++;//itself
    if(node->rightChild!=NULL)
    {
        // c++;
        c+=countWoolNodes(node->rightChild);//right
    }
    
    return c;
}



int WoolTree::countWoolNodes()
{
    int c=countWoolNodes(root);
    cout<<"Tree contains: "<<c<<" Wools."<< endl;
    return c;
}


void WoolTree::deleteWoolNode(std::string type)
{
    WoolNode *node=root;
    while(node!=NULL)
    {
        if(node->type.compare(type)<0)
        {
            node=node->rightChild;
        }
        else if(node->type.compare(type)>0)
        {
            node=node->leftChild;
        }
        else
        {
            break;
        }
    }
    if(node==NULL)
        cout << "Wool not found." << endl;
    //found
    //no child
    if(node->leftChild==NULL&&node->rightChild==NULL)
    {
        if(node==root)
        {
            root=NULL;
        }
        else if(node->parent->rightChild==node)
        {
            node->parent->rightChild=NULL;
        }
        
        else
        {
            node->parent->leftChild=NULL;
        }
        delete node;
    }
    //one child
    else if(node->rightChild!=NULL&&node->leftChild==NULL)
    {
        if(node==root)
        {
            root=node->rightChild;
            root->parent=NULL;
            delete node;
        }
        if(node->parent->rightChild==node)
        {
            node->parent->rightChild=node->rightChild;
        }
        else
            node->parent->leftChild=node->rightChild;
        
        delete node;
    }
    else if(node->leftChild!=NULL&&node->rightChild==NULL)
    {
        WoolNode *x=node->leftChild;
        if(node==root)
        {
            root=node->leftChild;
            root->parent=NULL;
            delete node;
        }
        if(node->parent->leftChild==node)
        {
            node->parent->leftChild=node->leftChild;
        }
        else
            node->parent->rightChild=node->leftChild;
        
        delete node;
    }
    
    //two children
    else
    {
        WoolNode *mins=node->rightChild;
        while(mins->leftChild!=NULL)
        {
            mins=mins->leftChild;
        }
        if(node==root)
        {
            root=mins;
        }
        else
        {
            if(node->parent->leftChild==node)
            {
                node->parent->leftChild=mins;
            }
            else
            {
                node->parent->rightChild=mins;
            }
        }
        
        if(node->rightChild!=mins)
        {
            node->rightChild->parent=mins;
            mins->parent->leftChild=mins->rightChild;
            if(mins->rightChild!=NULL)
            {
                mins->rightChild->parent=mins->parent;
            }
            mins->rightChild=node->rightChild;
            mins->parent=node->parent;
            node->leftChild->parent=mins;
            mins->leftChild=node->leftChild;
        }
        else
        {
            node->leftChild->parent=mins;
            mins->parent=node->parent;
            mins->leftChild=node->leftChild;
        }
        
        delete node;
    }
    
}


void WoolTree::DeleteAll(WoolNode * node)
{
    if(node->leftChild!=NULL)
    {
        DeleteAll(node->leftChild);
    }
    if(node->rightChild!=NULL)
    {
        DeleteAll(node->rightChild);
    }
    
    cout<<"Deleting: "<<node->type<<endl;
    delete node;
    
}



void WoolTree::insertfile(std::string filename)
{
    ifstream inFile;
    string type_s,quantity_s,clean_weight_s,micron_s,hauteur_meter_s;
    int quantity,clean_weight,micron,hauteur_meter;
    inFile.open(filename.c_str());
    string wool;
    
    if(inFile.good())
    {
        while( getline(inFile, wool)  )  //read/get every line of the file and store it
        {
            stringstream ss(wool);
            getline(ss, type_s, ',');
            getline(ss, quantity_s, ',');
            getline(ss, clean_weight_s, ',');
            getline(ss,micron_s,',');
            getline(ss,hauteur_meter_s);
            quantity = atoi(quantity_s.c_str());
            clean_weight=atoi(clean_weight_s.c_str());
            micron=atoi(micron_s.c_str());
            hauteur_meter=atoi(hauteur_meter_s.c_str());
            addWoolNode(type_s,quantity,clean_weight,micron,hauteur_meter);
            /*  cout<<ranking<<endl;
             cout<<title<<endl;
             cout<<releaseYear<<endl;
             cout<<quantity<<endl;*/
            
        }
    }
    else
    {
        cout<<"Error to open the file!"<<endl;
    }
    
}

int WoolTree::maxDepth(WoolNode * node)
{
    if(node==NULL||(node->leftChild==NULL&&node->rightChild==NULL)) return 0;
    int leftDepth =maxDepth(node->leftChild);
    int rightDepth=maxDepth(node->rightChild);
    
    return leftDepth>rightDepth?leftDepth+1:rightDepth + 1;
}

void WoolTree::maxDepth()
{
    maxDepth(root);
    if(root==NULL)
    {
        cout<<"please enter some data"<<endl;
    }
}

void WoolTree::minDepth()
{
    minDepth(root);
    if(root==NULL)
    {
        cout<<"please enter some data"<<endl;
    }
}
int WoolTree::minDepth(WoolNode *node)
{
    if(node == NULL || (node->leftChild == NULL && node->rightChild == NULL))
        return 0;
    
    int leftDepth = minDepth(node->leftChild);
    int rightDepth = minDepth(node->rightChild);
    
    return leftDepth < rightDepth ?leftDepth + 1 : rightDepth + 1;
}

/*print in the post order*/
void WoolTree::printWoolpostorder(WoolNode * node)
{
    if (node == NULL) return;
    // first recur on both subtrees
    if(node->leftChild!=NULL)
    {
        printWoolpostorder(node->leftChild);
    }
    cout<<"Wool: "<<node->type<<"Quantity: "<<node->quantity<<"Clean_weight: "<<node->clean_weight<<" Micron: "<<node->micron<<"Hauteur meter: "<<node->hauteur_meter<<endl;
    if(node->rightChild!=NULL)
    {
        printWoolpostorder(node->rightChild);
    }
}

void WoolTree::printWoolpostorder()
{
    printWoolpostorder(root);
}


void WoolTree::mirror(WoolNode * node)
{
    if (node==NULL)
    {
        cout<<"please enter some data"<<endl;
        return;
    }
    else
    {
        WoolNode * temp;
        
        // do the subtrees
        mirror(node->leftChild);
        mirror(node->rightChild);
        
        // swap the pointers in this node
        temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;
    }
    
}

void WoolTree::printLevelOrder(WoolNode *node)
{
    if (!node) return;
    queue<WoolNode*> nodesQueue;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;
    nodesQueue.push(node);
    while (!nodesQueue.empty())
    {
        WoolNode *currNode = nodesQueue.front();
        nodesQueue.pop();
        nodesInCurrentLevel--;
        if (currNode)
        {
            //currNode->type = "hi";
            cout << currNode->type<< " ";
            nodesQueue.push(currNode->leftChild);
            nodesQueue.push(currNode->rightChild);
            nodesInNextLevel += 2;
        }
        if (nodesInCurrentLevel == 0)
        {
            
        }
        nodesInCurrentLevel = nodesInNextLevel;
        nodesInNextLevel = 0;
    }
}


void WoolTree::printLevelOrder()
{
    printLevelOrder(root);
}

bool WoolTree::treeBuilt(){
    if (root != NULL){
        return true;
    }
    else{
        return false;
    }
    
}