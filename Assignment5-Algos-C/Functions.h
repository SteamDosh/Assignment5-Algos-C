#pragma once

#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;


class node
{
	private:
		int key;
	public:
		int value;

		node* Ptr = nullptr;

		node(int aVal) { value = aVal; key = aVal % 100; }
		int getKey() { return key; };
};

typedef std::map<int, node*> newMap;
typedef std::pair<int, node*> newPair;

void SelectFile();
void ReadFile(string aFileName);

void insertData(int aNum);
void insertNode(node* aNode, int aNum);
void longestChain();