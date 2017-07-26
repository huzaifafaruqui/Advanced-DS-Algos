// KMP string searching algorithm
// Copyright (c) Mohd Huzaifa Faruqui 2017. All rights reserved.

#ifndef KMP_H
#define KMP_H

#include <vector>
#include <iterator>

namespace adsa {

	template <typename patIter>
	void buildTable(std::vector<int>& skip_, patIter first, patIter last) {
		int len = 0, i = 1, m = skip_.size();

		skip_[0] = 0;

		while (i < m) {
			if (first[i] == first[len]) {
				++len;
				skip_[i] = len;
				i++;
			}
			else if (len) {
				len = skip_[len - 1];
			}
			else {
				skip_[i] = 0;
				i++;
			}
		}
	}


	template <typename textIter, typename patIter>
	textIter search(textIter first1, textIter last1, patIter first2,
		patIter last2) {

		if (first2 != last2) {  // pattern length != 0

			int m = std::distance(first2, last2), i, j;
			std::vector<int> skip_(m);

			buildTable(skip_, first2, last2);

			i = j = 0;

			while (first1 != last1) {
				if (*first1 == first2[i]) {
					++i;
					++first1;

					if (i == m) {
						return first1 - m;
					}
				}

				else {
					if (i) {
						i = skip_[i - 1];
					}
					else {
						++first1;
					}
				}

			}
		}

		return last1;
	}

} // namespace adsa

#endif // KMP_H