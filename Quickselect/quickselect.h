// Copyright (c) 2014-2018. Mohd Huzaifa Faruqui
// Quickselect - find nth largest/ smallest number in an unsorted array
// Complexity - Worst case O(n^2)
//				Best case O(n)
//				Average case O(n)


#ifndef QUICKSELECT_H
#define QUICKSELECT_H

#include <algorithm>
#include <functional>  // std::less

namespace adsa {

	template <typename Iter, typename Comp>
	Iter get_partition(Iter first, Iter last, Iter pivotIter, Comp comp) {
		auto pivotValue = *pivotIter;

		// swap pivot with last element
		std::iter_swap(last - 1, pivotIter);

		Iter i = first;

		// get correct location of pivot
		// by moving all "smaller" elements to left
		for (Iter j = first; j != last - 1; ++j) {
			if (comp(*j, pivotValue)) {
				std::iter_swap(i, j);
				++i;
			}
		}

		// put pivot to its correct location
		std::iter_swap(i, last - 1);

		// return iterator to pivot
		return i;

	}

	template <typename Iter, typename Comp = std::less<> >
	Iter nth_element(Iter first, Iter last, int n, Comp comp = Comp()) {

		// if n is more than no. of elements
		if (n > std::distance(first, last)) {
			return last;
		}

		Iter pivotIter = first;	// TODO : Improve pivot selection

		// move pivot to its correct location
		pivotIter = get_partition(first, last, pivotIter, comp);

		// get location of pivot element
		int pivotIdx = std::distance(first, pivotIter);

		// found nth element
		if (n == pivotIdx) {
			return pivotIter;
		}
		// else if nth element is less than pivot element
		// then it lies in left of pivot
		else if (n < pivotIdx) {
			return nth_element(first, pivotIter, n, comp);
		}
		// else it lies in right of pivot
		// get (n - pivot_index)th element from right subarray
		else {
			return  nth_element(pivotIter + 1, last, n - pivotIdx - 1, comp);
		}

	}
} // namespace adsa


#endif // QUICKSELECT_H
