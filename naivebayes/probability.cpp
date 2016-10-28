#include <iostream>
#include <utility>

#include "probability.h"

namespace NaiveBayes {

	// DEFAULT CONSTRUCTOR
	PriorProbability::PriorProbability(void)
	{
		index = -1;
		name = "not defined";
	}

	// COPY CONSTRUCTOR

	PriorProbability::PriorProbability(const PriorProbability& other_prior_probability)
	{
		index = other_prior_probability.index;
		name  = other_prior_probability.name;
		prior_probs = other_prior_probability.prior_probs;
	}

	// DESTRUCTOR

	PriorProbability::~PriorProbability(void)
	{
	}

	// ASSIGNMENT OPERATOR

	PriorProbability& PriorProbability::operator = (const PriorProbability& other_prior_probability)
	{
		if(this != &other_prior_probability) {
			index = other_prior_probability.index;
			name  = other_prior_probability.name;
			prior_probs = other_prior_probability.prior_probs;
		}

		return(*this);
	}


	// EQUAL TO OPERATOR

	bool PriorProbability::operator == (const PriorProbability& other_prior_probability) const
	{
		if(index == other_prior_probability.index && name == other_prior_probability.name && prior_probs == other_prior_probability.prior_probs)
			return(true);
		else
			return(false);
	}

	// DEFAULT CONSTRUCTOR
	ConditionalProbability::ConditionalProbability(void)
	{
		indices = std::make_pair(-1, -1);
		names   = std::make_pair("not defined", "not defined");
		std::cout << "indices = " << indices.first << "," << indices.second << "\n";
		std::cout << "names = " << names.first << "," << names.second << "\n";

	}

	// COPY CONSTRUCTOR

	ConditionalProbability::ConditionalProbability(const ConditionalProbability& other_conditional_probability)
	{
		indices = other_conditional_probability.indices;
		names  = other_conditional_probability.names;
		conditional_probs = other_conditional_probability.conditional_probs;
	}

	// DESTRUCTOR

	ConditionalProbability::~ConditionalProbability(void)
	{
	}

	// ASSIGNMENT OPERATOR

	ConditionalProbability& ConditionalProbability::operator = (const ConditionalProbability& other_conditional_probability)
	{
		if(this != &other_conditional_probability) {
			indices = other_conditional_probability.indices;
			names  = other_conditional_probability.names;
			conditional_probs = other_conditional_probability.conditional_probs;
		}

		return(*this);
	}


	// EQUAL TO OPERATOR

	bool ConditionalProbability::operator == (const ConditionalProbability& other_conditional_probability) const
	{
		if(indices == other_conditional_probability.indices && names == other_conditional_probability.names && conditional_probs == other_conditional_probability.conditional_probs)
			return(true);
		else
			return(false);
	}

};

