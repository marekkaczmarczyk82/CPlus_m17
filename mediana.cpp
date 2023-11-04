#include <iostream>

using namespace std;

	void pisztab( ostream&, const int[], int );
	void inssort( int[], int );
	double minmaxmed( const int[], int, int&, int& );

		int main()
		{
			int min, max, tab[] = { 9,7,2,6,4,2,7,9,2,9,5,2 }, size = sizeof( tab )/ sizeof( int );

			double mediana = minmaxmed( tab, size, min, max );

				cout << "Tablica oryginalna: ";
					pisztab( cout, tab, size );

			inssort( tab, size );

				cout << "Tablica posortowana:";
					pisztab( cout, tab, size );
		}


	void pisztab( ostream& str, const int t[], int size )
	{
		str << "[" ;
			
			for( int i = 0; i < size; ++i ) str << t[i] << " ";

		str << "]" << endl;

	}

	void inssort( int a[], int size )
	{
		int i, indmin = 0;

			for( i = 1; i < size; ++i )
				if ( a[i] < a[indmin] ) indmin = i;
			if( indmin != 0 )
			{
				int p = a[0];
				a[0] = a[indmin];
				a[indmin] = p;
			}

			for( i = 2; i < size; ++ i )
			{
				int j = i, v = a[i];
				while( v < a[j - 1] )
				{
					a[j] = a[j - 1];
					j--;
				}
				if( i != j ) a[j] = v;
			}

	}


	double minmaxmed( const int t[], int size, int& min, int& max )
	{
		int * tab = new int[size];

			for( int i = 0; i < size; ++i )
				tab[i] = t[i];

			inssort( tab, size );

			min = tab[0];
			max = tab[size - 1];

			double mediana = size%2 == 0 ? 0.5 * ( tab[size/2] + tab[size/2 - 1] ) : tab[size/2];

			delete [] tab;

			return mediana;

	}
