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

      variables_pointer->set_name(0, "clump_thickness");
      variables_pointer->set_name(1, "cell_size_uniformity");
      variables_pointer->set_name(2, "cell_shape_uniformity");
      variables_pointer->set_name(3, "marginal_adhesion");
      variables_pointer->set_name(4, "single_epithelial_cell_size");
      variables_pointer->set_name(5, "bare_nuclei");
      variables_pointer->set_name(6, "bland_chromatin");
      variables_pointer->set_name(7, "normal_nucleoli");
      variables_pointer->set_name(8, "mitoses");
      variables_pointer->set_name(9, "diagnose");

      // Instances

      Instances* instances_pointer = data_set.get_instances_pointer();

      instances_pointer->split_random_indices();

      const Matrix<std::string> inputs_information = variables_pointer->arrange_inputs_information();
      const Matrix<std::string> targets_information = variables_pointer->arrange_targets_information();

      const Vector< Statistics<double> > inputs_statistics = data_set.scale_inputs_minimum_maximum();
      const Matrix<double> data = data_set.get_data();
      std::cout << "data rows = " << data.get_rows_number() << "\n" << "data columns = " << data.get_columns_number() << "\n";
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
