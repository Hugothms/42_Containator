/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:31:55 by llefranc          #+#    #+#             */
/*   Updated: 2021/01/27 16:00:50 by llefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TESTS_HPP
#define LIST_TESTS_HPP

#include "../includes_and_utils/tester.hpp"

template <typename T>
void	testSizeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "size"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << cont.size();
}

template <typename T>
void	testEmptyList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "empty"));
	std::cout << "\n---------------------";
	
	printTestName(name);	std::cout << lis.empty();
}

template <typename T>
void	testIteratorsList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "operator++");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " | ";

	printTestName(name, "++operator");
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout << *it << " | ";

	if (cont.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); it--)
			if (it != cont.end())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_iterator it = cont.end(); it != cont.begin(); --it)
			if (it != cont.end())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testReverseIteratorsList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "reverse iterators"));
	std::cout << "\n---------------------";
	
	printTestName(name, "++operator");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); ++it)
		std::cout << *it << " | ";

	printTestName(name, "operator++");
	for (typename T::const_reverse_iterator it = cont.rbegin(); it != cont.rend(); it++)
		std::cout << *it << " | ";	

	if (cont.size())
	{
		printTestName(name, "operator--");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); it--)
			if (it != cont.rend())
				std::cout << *it << " | ";

		printTestName(name, "--operator");
		for (typename T::const_reverse_iterator it = cont.rend(); it != cont.rbegin(); --it)
			if (it != cont.rend())
				std::cout << *it << " | ";
	}
}

template <typename T>
void	testFrontList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.front();
}

template <typename T>
void	testBackList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "back"));
	std::cout << "\n---------------------";

	printTestName(name);
	if (cont.size()) // To prevent overflow
		std::cout << cont.back();
}

template <typename T>
void	testPushBackList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "push_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp = cont;
	tmp.push_back(*x);

	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testPopBackList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "pop_back"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	if (cont.size())
	{
		T tmp = cont;
		tmp.pop_back();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testPushFrontList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "push_front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	// Allows to value initialize (case size is 0, we can't assign lis.front())
	typename T::value_type* x = new typename T::value_type ();
	if (lis.size())
		*x = lis.front();

	T tmp = lis;
	tmp.push_front(*x);

	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testPopFrontList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "pop_front"));
	std::cout << "\n---------------------";
	
	printTestName(name);
	
	if (lis.size())
	{
		T tmp = lis;
		tmp.pop_front();
		printContainer(name, tmp);
	}
}

template <typename T>
void	testClearList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "clear"));
	std::cout << "\n---------------------";
	
	T tmp = cont;
	printTestName(name);	std::cout << "size before clear: " << tmp.size();
	tmp.clear();
	
	printTestName(name);	std::cout << "size after clear: " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	printContainer(name, tmp);

	delete x;
}

template <typename T>
void	testSwapList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "swap"));
	std::cout << "\n---------------------";
	
	T tmp(cont);
	T tmp2(cont);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.push_back(*x);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	tmp2.swap(tmp);
	printContainer(name, tmp2);

	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();

	swap(tmp2, tmp);
	printTestName(name);	std::cout << "size of tmp = " << tmp.size() << " and size of tmp2 = " << tmp2.size();
	printContainer(name, tmp2);

	delete x;
}

template <typename T>
void	testResizeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "resize"));
	std::cout << "\n---------------------";

	T tmp = cont;

	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	tmp.resize(3, *x);
	printContainer(name, tmp);

	printTestName(name);	std::cout << "size of tmp after resize = " << tmp.size();
	
	delete x;
}

/**
*	Test assign with iterators' range.
*/
template <typename T>
void	testAssignRangeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "assign iterator range"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();

	T tmp2 = cont;
	tmp.resize(3, *x);
	tmp2.assign(tmp.begin(), tmp.end());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testAssignNElemList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "assign n elems"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	// Allows to value initialize (case size is 0, we can't assign cont.front())
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
		*x = cont.front();
		
	tmp.resize(3, *x);

	T tmp2 = cont;
	tmp2.assign(tmp.size(), tmp.front());

	printTestName(name);	std::cout << "size after assign = " << tmp2.size();
	printContainer(name, tmp2);
		
	delete x;
}

/**
*	Inserts one element.
*/
template <typename T>
void	testInsert1ElemList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert 1 elem"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont[0])
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		typename T::iterator it = tmp.begin();
		++it;
		printTestName(name);	std::cout << "return value: " << *tmp.insert(it, *x);
	}
	printTestName(name);	std::cout << "return value: " << *tmp.insert(tmp.begin(), *x);
	printTestName(name);	std::cout << "return value: " << *tmp.insert(tmp.end(), *x);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	delete x;
}

/**
*	Inserts n elements.
*/
template <typename T>
void	testInsertNElemList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert n elem"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	// Allows to value initialize (case size is 0, we can't assign cont[0])
	typename T::value_type* x = new typename T::value_type ();
	if (cont.size())
	{
		*x = cont.front();
		typename T::iterator it = tmp.begin();
		++it;
		tmp.insert(it, 5, *x);
	}
	tmp.insert(tmp.begin(), 5, *x);
	tmp.insert(tmp.end(), 5, *x);
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	delete x;
}

/**
*	Inserts an iterators' range of elements.
*/
template <typename T>
void	testInsertRangeList(T& cont)
{
	std::string name(getTestName(getTestNumber(0), "insert iterator range"));
	std::cout << "\n---------------------";

	T tmp = cont;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();

	tmp.insert(tmp.begin(), cont.begin(), cont.end());
	if (tmp.size())
	{
		typename T::iterator it = tmp.begin();
		++it;
		tmp.insert(it, cont.begin(), cont.end());
	}
	tmp.insert(tmp.end(), cont.begin(), cont.end());
	tmp.insert(tmp.end(), cont.begin(), cont.begin());
	
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);
}

template <typename T>
void	testReverseList(T& lis)
{
	std::string name(getTestName(getTestNumber(0), "reverse"));
	std::cout << "\n---------------------";

	T tmp = lis;
	printTestName(name);	std::cout << "size of tmp = " << tmp.size();
	printContainer(name, tmp);

	tmp.reverse();
	
	printTestName(name);	std::cout << "size after resize = " << tmp.size();
	printContainer(name, tmp);
}


template <typename T>
void	testNotConstList(T& lis, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING LIST " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tLIST TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for non-const lists
	testSizeList(lis);
	testEmptyList(lis);
	testIteratorsList(lis);
	testReverseIteratorsList(lis);
	testFrontList(lis);
	testBackList(lis);
	testPushBackList(lis);
	testPopBackList(lis);
	testPushFrontList(lis);
	testPopFrontList(lis);
	testClearList(lis);
	testSwapList(lis);
	testResizeList(lis);
	testAssignRangeList(lis);
	testAssignNElemList(lis);
	testInsert1ElemList(lis);
	testInsertNElemList(lis);
	testInsertRangeList(lis);
	testReverseList(lis);
}

template <typename T>
void	testConstList(T& lis, int testNb)
{
	std::cout << "\n\n--------------------------------\n";
	std::cout << "------\tTESTING CONST LIST " << testNb << " ------\n";
	std::cout << "--------------------------------\n";
	
	std::cout << "\t\tLIST TYPE: ";
	print_type<typename T::value_type>();
	
	// Tests for const lists
	testSizeList(lis);
	testIteratorsList(lis);
	testReverseIteratorsList(lis);
	testFrontList(lis);
	testBackList(lis);
	testEmptyList(lis);
}

#endif