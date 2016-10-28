#ifndef __PROBABILITY_H__
#define __PROBABILITY_H__

// System includes

#include <string>
#include <unordered_map>

namespace NaiveBayes {

	struct pair_hash {
		template <class T1, class T2>
			std::size_t operator () (const std::pair<T1,T2> &p) const {
				auto h1 = std::hash<T1>{}(p.first);
				auto h2 = std::hash<T2>{}(p.second);

				// Mainly for demonstration purposes, i.e. works but is overly simple
				// In the real world, use sth. like boost.hash_combine
				return h1 ^ h2;  
			}
	};

	// This class is used to store prior probability of a attribute value.
	/// index: variable index;
	/// prior_probs: prior probabilities of a variable:
	/// the first double: attribute value of a variable;
	/// the second double: prior probability of the given attribute value.

	class PriorProbability {
		private:
			int index;
			std::string name;
			std::unordered_map<double, double> prior_probs;
		public:
			// DEFAULT CONSTRUCTOR
			explicit PriorProbability(void);

			// COPY CONSTRUCTOR

			PriorProbability(const PriorProbability& new_prior_probability);

			// DESTRUCTOR

			virtual ~PriorProbability(void);

			// ASSIGNMENT OPERATOR

			PriorProbability& operator = (const PriorProbability& new_prior_probability);

			// EQUAL TO OPERATOR

			bool operator == (const PriorProbability& new_prior_probability) const;

			void set_index(int new_index)
			{
				index = new_index;
			}

			int get_index(void)
			{
				return index;
			}

			void set_name(std::string new_name)
			{
				name = new_name;
			}

			std::string get_name(void)
			{
				return name;
			}

			void set_prior_probs(std::unordered_map<double, double>& new_prior_probs)
			{
				prior_probs = new_prior_probs;
			}

			std::unordered_map<double, double>& get_prior_probs(void) 
			{
				return prior_probs;
			}
	};

	// This class is used to store conditional probability of a attribute value.
	/// index: variable index;
	/// prior_probs: prior probabilities of a variable:
	/// the first double: attribute value of a variable;
	/// the second double: prior probability of the given attribute value.

	class ConditionalProbability {
		private:
			std::pair<int, int> indices;
			std::pair<std::string, std::string> names;
			std::unordered_map< std::pair<double, double>, double, pair_hash > conditional_probs;
		public:
			// DEFAULT CONSTRUCTOR
			explicit ConditionalProbability(void);

			// COPY CONSTRUCTOR

			ConditionalProbability(const ConditionalProbability& other_conditional_probability);

			// DESTRUCTOR

			virtual ~ConditionalProbability(void);

			// ASSIGNMENT OPERATOR

			ConditionalProbability& operator = (const ConditionalProbability& other_conditional_probability);

			// EQUAL TO OPERATOR

			bool operator == (const ConditionalProbability& other_conditional_probability) const;

			void set_indices(std::pair<int,int>& new_indices)
			{
				indices = new_indices;
			}

			void set_indices(int index0, int index1)
			{
				indices = std::make_pair(index0, index1);
			}

			std::pair<int, int>& get_indices(void)
			{
				return(indices);
			}

			void set_names(std::pair<std::string, std::string>& new_names)
			{
				names = new_names;
			}

			void set_names(const std::string& name0, const std::string& name1)
			{
				names = std::make_pair(name0, name1);
			}

			std::pair<std::string, std::string>& get_names(void)
			{
				return(names);
			}

			void set_conditional_probs(const std::unordered_map< std::pair<double, double>, double, pair_hash >& new_conditional_probs)
			{
				conditional_probs = new_conditional_probs;
			}

			std::unordered_map< std::pair<double, double>, double, pair_hash >& get_conditional_probs(void)
			{
				return(conditional_probs);
			}
	};

}

#endif
