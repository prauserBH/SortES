#pragma once

namespace ES
{
	template<class T>
	void swap(T& elem1, T& elem2)
	{
		T tmp = elem1;
		elem1 = elem2;
		elem2 = tmp;
	}

	template<class It, class Comparator>
	It partition(It start, It end, Comparator& comp)
	{
		auto pivotValue = *start;
		It pivotPosition = start;

		for (It pos = start+1; pos < end; pos++)
		{
			if (comp(pivotValue,*pos))
			{
				pivotPosition++;

				swap(*pos, *pivotPosition);
				
			}
		}

		swap(*start, *pivotPosition);

		return pivotPosition;
	}

	template<class It, class Comparator>
	void quickSort(It start, It end, Comparator& comp)
	{
		auto p = partition(start, end, comp);

		quickSort(start, p - 1, comp);

		quickSort(p + 1, end, comp);
	}
}