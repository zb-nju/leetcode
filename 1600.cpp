#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        this->kingName = kingName;
    }

    void birth(string parentName, string childName) {
        this->edges[move(parentName)].push_back(move(childName));
    }


    void death(string name) {
        this->dead.insert(movw(name));
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(kingName, ans);
        return ans;
    }

private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string kingName;

    void dfs(string now, vector<string> &ans){
        if(!dead.count(now))
            ans.push_back(now);
        for(string &name: edges[now]){
            dfs(name, ans);
        }
    }
};


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

// struct Node
// {
//     string name;
//     bool alive;
//     Node* nextBrother;
//     Node* firstChild;
//     Node(string name):name(name), alive(true), nextBrother(nullptr), firstChild(nullptr){}
// };



// class ThroneInheritance {
// public:
//     ThroneInheritance(string kingName) {
//         king = new Node(kingName);
//     }

//     void birth(string parentName, string childName) {
//         Node* parent = find(parentName, king);
//         Node* child = parent->firstChild;
//         if(child == nullptr)
//             parent->firstChild = new Node(childName);
//         else{
//             while(child->nextBrother != nullptr)
//                 child = child->nextBrother;
//             child->nextBrother = new Node(childName);
//         }
//     }

//     void death(string name) {
//         find(name, king)->alive = false;
//     }

//     vector<string> getInheritanceOrder() {
//         vector<string> ans;
//         getAns(king, ans);
//         return ans;
//     }

// private:
//     Node* king;
//     Node* find(string name, Node* now){
//         if(now == nullptr)
//             return nullptr;
//         if(now->name == name)
//             return now;
//         Node* ret = find(name, now->firstChild);
//         return ret == nullptr ? find(name, now->nextBrother) : ret;
//     }

//     void getAns(Node* now, vector<string> &ans){
//         if(now == nullptr)
//             return;
//         if(now->alive)
//             ans.push_back(now->name);
//         getAns(now->firstChild, ans);
//         getAns(now->nextBrother, ans);
//     }
// };

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */