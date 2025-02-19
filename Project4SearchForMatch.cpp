#include "myheader.h"

int SearchForMatch(string first[], string firstSearch, string last[],
					string lastSearch, int count)
{
	int match = -1;

	for (int i = 0; i < count; i++)
	{
		if (first[i] == firstSearch && last[i] == lastSearch)
		{
		match = i;
		cout << "Found." << endl << endl;
		}
	}
	return match;

}
