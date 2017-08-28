import java.lang.Math;

public class Solution{
	private double findKthSortedArrays( int A[], int astart, int aend, int B[], int bstart, int bend, int k )
	{
		int m = aend - astart, n = bend - bstart;
		if( m < n )
			return findKthSortedArrays( B, bstart, bend, A, astart, aend, k );

		if( n == 0 )
			return A[ astart + k - 1 ];
		if( k == 1 )
			return Math.min( A[astart], B[bstart] );

		int pb = Math.min( k / 2 ), pa = k - pb;
	}
};
