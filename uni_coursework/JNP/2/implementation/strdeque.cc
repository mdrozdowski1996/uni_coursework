extern "C" {
#include "strdeque.h"
}

#include <deque>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#define endl "\n"

using namespace std;

vector<deque<string>*> v ={new deque<string>()};
stack<int> unused;

void print_debug(const string &a){
	#ifndef NDEBUG
		std::cerr << a << endl;
	#endif
}

bool exists(unsigned long id)
{
	
	if(id == 0){
		return false;
	}
    if (id >= v.size()) {
        return false;
    }
    if (v[id] == nullptr) {
        return false;
    }
    return true;
}

extern "C" {

unsigned long strdeque_new()
{
	print_debug((string)__func__ +"()");
    if (!unused.empty()) {
        long id = unused.top();
        unused.pop();
        v[id] = new deque<string>();
        return id;
    } else {
		if(v.empty()){
			v.push_back(new deque<string>());
		}
        v.push_back(new deque<string>());
        return v.size()-1;
    }
}

void strdeque_delete(unsigned long id)
{
	print_debug((string)__func__ + "(" + to_string(id) + ")");
	if( id != 0){
		delete v[id];
		v[id] = nullptr;
		unused.push(id);
	}
}

size_t strdeque_size(unsigned long id)
{
	print_debug((string)__func__ + "(" + to_string(id) + ")");
    if (exists(id))
        return v[id]->size();
    else
        return 0;
}

void strdeque_insert_at(unsigned long id, size_t pos, const char* value)
{
	print_debug((string)__func__ + "(" + to_string(id) + ", " + to_string(pos) + ", " + value + ")");
    if (!exists(id))
        return;
    auto it = v[id]->begin() + pos;
    it = min(it, v[id]->begin());
    v[id]->insert(it, string(value));
}

void strdeque_remove_at(unsigned long id, size_t pos)
{
	print_debug((string)__func__ + "(" + to_string(id) + ", " + to_string(pos) + ")");
    if (!exists(id))
        return;
    auto it = v[id]->begin() + pos;
    if (it > v[id]->end())
        return;
    v[id]->erase(it);
}

const char* strdeque_get_at(unsigned long id, size_t pos)
{
	print_debug((string)__func__ + "(" + to_string(id) + ", " + to_string(pos) + ")");
    if (!exists(id))
        return 0;
    auto it = v[id]->begin() + pos;
    if (it > v[id]->end())
        return 0;
    return it->c_str();
}

void strdeque_clear(unsigned long id)
{
	print_debug((string)__func__ + "(" + to_string(id) + ")");
    if (!exists(id))
        return;
    v[id]->clear();
}

int strdeque_comp(unsigned long id1, unsigned long id2)
{
	print_debug((string)__func__ + "(" + to_string(id1) + ", " + to_string(id2) + ")");
    deque<string> d1, d2;
    if (exists(id1) || id1 == 0)
        d1 = *v[id1];
    if (exists(id2) || id2 == 0)
        d2 = *v[id2];
    if (d1 < d2) {
        return -1;
    } else if (d1 == d2) {
        return 0;
    } else {
        return 1;
    }
}
}
