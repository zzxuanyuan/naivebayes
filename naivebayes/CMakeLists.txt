set(NAIVEBAYES_HDRS
variables.h 
    instances.h 
    missing_values.h 
    data_set.h 
    vector.h 
    matrix.h 
    opennn.h 
    probability.h
)

set(NAIVEBAYES_SRCS
variables.cpp 
    instances.cpp 
    missing_values.cpp 
    data_set.cpp
    probability.cpp
        )

add_library(naivebayes ${NAIVEBAYES_SRCS})
target_link_libraries(naivebayes tinyxml2)
