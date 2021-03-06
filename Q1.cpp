#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[10][10], m, i, j, k, ref = 1, irr = 1, sym = 1, ans = 1, tr = 1;
	cout << "Enter the order of the relation  matrix" << endl;
	cin >> m;
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	// Checking reflexivity
	for (i = 0; i < m; i++)
	{
		if (!a[i][j])
			ref = 0;
		else
			irr = 1;
	}
	// Checking symmetricity
	for(i = 0; i < m; i++)
		for (j = 0; j < m; j++)
		{
			if (a[i][j] && !a[j][i])
				sym = 0;
			if (a[i][j] && a[j][i] && (i - j))
				ans = 0;
		}
	// Checking transitivity
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < m; k++)
				if (a[i][j] && a[j][k] && !a[i][k])
					tr = 0;
	if (ref)
		cout << "Relation reflexive" << endl;
	else if (irr)
		cout << "Relation irrefelxive" << endl;
	else
		cout << "Relation is neither reflexive nor irreflexive" << endl;
	if (sym)
		cout << "Relation symmetric" << endl;
	if (ans)
		cout << "Relation anti symmetric" << endl;
	if (!sym && !ans)
		cout << "Relation is not symmetric" << endl;
	if (tr)
		cout << "Relation is transitive" << endl;
	else
		cout << "Relation is not transitive" << endl;
	if (ref && sym && tr)
		cout << "Relation equivalence" << endl;
	else
		cout << "Relation is not an equivalence relation" << endl;
	if (ref && ans && tr)
		cout << "Relation is a partial ordering relation" << endl;
	else
		cout << "This is not a poset" << endl;
	return(0);
}