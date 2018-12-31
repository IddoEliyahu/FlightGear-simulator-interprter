//
// Created by dvir on 12/22/18.
//

#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <string>
#include <map>
#include <mutex>

using namespace std;

class SymbolTable {
    map<string,double> symbolTable;
    static SymbolTable *map_instance;
public:
    static inline SymbolTable *instance(){
        if(map_instance == nullptr){
            map_instance = new SymbolTable();
        }
        return map_instance;
    }
    inline const map<string, double> &getVarTable() const{
        return this->symbolTable;
    }
    inline void setValue(string key, double value){
        mutex mtx;
        mtx.lock();
        this->symbolTable[key] = value;
    mtx.unlock();
    }
    inline double getValue(const string &key){
        if(this->symbolTable.count(key) ==  1)
            return this->symbolTable[key];
        else
            throw runtime_error("var: " + key + "not exists");

    }


};


#endif //PROJECT_SYMBOLTABLE_H
