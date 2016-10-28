/****************************************************************************************************************/
/*                                                                                                              */ 
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.artelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   B R E A S T   C A N C E R   A P P L I C A T I O N                                                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */ 
/*   Artelnics - Making intelligent use of data                                                                 */
/*   robertolopez@artelnics.com                                                                                 */
/*                                                                                                              */  
/****************************************************************************************************************/

// This is a pattern recognition problem.

// System includes

#include <iostream>
#include <time.h>
#include <unordered_map>

// OpenNN includes

#include "../../naivebayes/naivebayes.h"

using namespace NaiveBayes;

int main(void)
{
	try
	{
		std::cout << "NaiveBayes. Breast Cancer Application." << std::endl;

		srand((unsigned)time(NULL));

		// Data set

		DataSet data_set;

		data_set.set_data_file_name("./data/breast_cancer.dat");

		data_set.load_data();

		data_set.set_file_type("dat");

		// Variables

		Variables* variables_pointer = data_set.get_variables_pointer();

		static const double arr_input[] = {1,2,3,4,5,6,7,8,9,10};
		Vector<double> range_input(arr_input, arr_input + sizeof(arr_input) / sizeof(arr_input[0]) );

		variables_pointer->set_name(0, "clump_thickness");
		variables_pointer->set_use(0, Variables::Input);
		variables_pointer->set_range(0, range_input);

		variables_pointer->set_name(1, "cell_size_uniformity");
		variables_pointer->set_use(1, Variables::Input);
		variables_pointer->set_range(1, range_input);

		variables_pointer->set_name(2, "cell_shape_uniformity");
		variables_pointer->set_use(2, Variables::Input);
		variables_pointer->set_range(2, range_input);

		variables_pointer->set_name(3, "marginal_adhesion");
		variables_pointer->set_use(3, Variables::Input);
		variables_pointer->set_range(3, range_input);

		variables_pointer->set_name(4, "single_epithelial_cell_size");
		variables_pointer->set_use(4, Variables::Input);
		variables_pointer->set_range(4, range_input);

		variables_pointer->set_name(5, "bare_nuclei");
		variables_pointer->set_use(5, Variables::Input);
		variables_pointer->set_range(5, range_input);

		variables_pointer->set_name(6, "bland_chromatin");
		variables_pointer->set_use(6, Variables::Input);
		variables_pointer->set_range(6, range_input);

		variables_pointer->set_name(7, "normal_nucleoli");
		variables_pointer->set_use(7, Variables::Input);
		variables_pointer->set_range(7, range_input);

		variables_pointer->set_name(8, "mitoses");
		variables_pointer->set_use(8, Variables::Input);
		variables_pointer->set_range(8, range_input);

		static const double arr_target[] = {0,1};
		Vector<double> range_target(arr_target, arr_target + sizeof(arr_target) / sizeof(arr_target[0]) );
		variables_pointer->set_name(9, "diagnose");
		variables_pointer->set_use(9, Variables::Target);
		variables_pointer->set_range(9, range_target);

		// Instances

		Instances* instances_pointer = data_set.get_instances_pointer();

		instances_pointer->split_random_indices();

		const Matrix<std::string> inputs_information = variables_pointer->arrange_inputs_information();
		const Matrix<std::string> targets_information = variables_pointer->arrange_targets_information();

		const Vector< Statistics<double> > inputs_statistics = data_set.scale_inputs_minimum_maximum();

		const Vector<double> range = variables_pointer->get_range(0);
		std::cout << "size of range = " << range.size() << std::endl;

		const Matrix<double> data = data_set.get_data();
		std::cout << "data rows = " << data.get_rows_number() << "\n" << "data columns = " << data.get_columns_number() << "\n";

		std::unordered_map<int, PriorProbability> prior_probs = data_set.calculate_training_target_prior_probabilities();
		std::cout << "mymap contains:";
		for ( auto it = prior_probs.begin(); it != prior_probs.end(); ++it )
			std::cout << " " << it->first << ":";
		std::cout << std::endl;
		std::cout << "prior_probs's buckets contain: " << prior_probs.bucket_count() << " buckets\n";

		for ( unsigned i = 0; i < prior_probs.bucket_count(); ++i) {
			std::cout << "bucket #" << i << " contains:";
			for ( auto local_it = prior_probs.begin(i); local_it!= prior_probs.end(i); ++local_it )
				std::cout << " " << local_it->first << ":" << (local_it->second).get_name();
			std::cout << std::endl;
		}
		std::unordered_map<double, double> prob_map = prior_probs[9].get_prior_probs();
		std::cout << prob_map[0] << " " << prob_map[1] << "\n";

		std::unordered_map< std::pair<int, int>, ConditionalProbability, pair_hash> conditional_probs;
		conditional_probs = data_set.calculate_training_conditional_probabilities();
//		for ( auto it = conditional_probs.begin(); it != conditional_probs.end(); ++it )
//			std::cout << " " << (it->first).first << "," << (it->first).second;
//		std::cout << "\n";
		return(0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;

		return(1);
	}
}  


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2015 Roberto Lopez
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
