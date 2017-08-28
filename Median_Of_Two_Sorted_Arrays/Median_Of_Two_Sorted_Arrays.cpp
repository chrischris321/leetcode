#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
private:
	double findKthSortedArrays( int A[], int m, int B[], int n, int k )
	{
		if( m < n )
		{
			std::swap( m, n );
			std::swap( A, B );
		}

		if( n == 0 )
			return A[ k - 1 ];

		if( k == 1 )
			return std::min( A[0], B[0] );

		int pb = std::min( k / 2, n ), pa = k - pb;
		if( A[ pa - 1 ] > B[ pb - 1 ] )
			return findKthSortedArrays( A, m, B + pb, n - pb, k - pb );
		else if( A[ pa - 1 ] < B[ pb - 1 ] )
			return findKthSortedArrays( A + pa, m - pa, B, n, k - pa );
		else
			return A[ pa - 1 ];
	}

public:
	double findMedianSortedArrays( int A[], int m, int B[], int n )
	{
		if( ( n + m ) & 1 )		// odds
			return findKthSortedArrays( A, m, B, n, ( n + m  ) / 2 + 1 );
		else 					// even
			return ( findKthSortedArrays( A, m, B, n, ( n + m ) / 2 + 1 ) + findKthSortedArrays( A, m, B, n, ( n + m ) / 2 ) ) / 2.0;
	}

	double findMedianSortedArrays( std::vector< int > &vec1, std::vector< int > &vec2 )
	{
		if( vec1.size() == 0 ) 
		{
			vec1.push_back( 0 );
			return findMedianSortedArrays( &vec1[0], 0, &vec2[0], vec2.size() );
		}
		if( vec2.size() == 0 )
		{
			vec2.push_back( 0 );
			return findMedianSortedArrays( &vec1[0], vec1.size(), &vec2[0], 0 );
		}
		return findMedianSortedArrays( &vec1[0], vec1.size(), &vec2[0], vec2.size() );
	}
};

int main()
{
	int n, m;
	int A[100], B[100];
	Solution s;

	while( std::cin >> n )
	{
		for( int i = 0; i < n; i++ )
			std::cin >> A[i];
		std::cin >> m;
		for( int i = 0; i < m; i++ )
			std::cin >> B[i];

		std::cout << s.findMedianSortedArrays( A, n, B, m ) << std::endl;
	}

	return 0;
}
