#include "Functions.h"


newMap Map = {};

const int MAXSIZE = 100;
node* arrayMap[MAXSIZE] = {};

void SelectFile()
{
	cout << "\nEnter the name of the file (ie words.txt)" << endl;
	string input;
	cin >> input;

	ReadFile(input);
}

void ReadFile(string aFileName)
{
	ifstream fin(aFileName);

	if (!fin.good())
	{
		cerr << "Could not open data file!\n";
		return;
	}

	for (string word; fin >> word;)
	{
		insertData(stoi(word));
	}

	fin.close();

	cout << "Finished loading tree" << endl;
}

void insertData(int aInt)
{
	int key = aInt % 100;
	/*if (Map.find(key) == Map.end())
	{
		Map.insert(newPair(key, new node(aInt)));
	}
	else
	{
		insertNode(Map[key], aInt);
		return;
	}	*/

	if (arrayMap[key])
	{
		insertNode(arrayMap[key], aInt);
		return;
	}
	else
	{
		arrayMap[key] = new node(aInt);
	}

}

void insertNode(node* aNode, int aInt)
{
	while (aNode->Ptr != nullptr)
	{
		aNode = aNode->Ptr;
	}

	aNode->Ptr = new node(aInt);
}

void longestChain()
{
	int highest = 0;
	int highestCount = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		int count = 0;
		if (arrayMap[i])
		{
			node* aNode = arrayMap[i];

			while (aNode->Ptr != nullptr)
			{
				aNode = aNode->Ptr;
				count++;
				if (count > highestCount)
				{
					highestCount++;
					highest = aNode->value % 100;
				}
			}
		}
	}
	/*for (newMap::iterator it = Map.begin(); it != Map.end(); ++it)
	{
		int count = 0;
		node* aNode = it->second;
		while (aNode->Ptr != nullptr)
		{
			aNode = aNode->Ptr;
			count++;
			if (count > highestCount)
			{
				highestCount++;
				highest = aNode->value % 100;
			}
		}
	}*/
	cout << highest << " has the longest chain with " << highestCount << endl;
}