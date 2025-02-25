#include <cstdio> //required by scotch.h
#include "scotch.h"
#include <vector>
#include <iostream>

// foc for programming with scotch
// https://gitlab.inria.fr/scotch/scotch/-/blob/master/doc/scotch_hands-on7.0.pdf?ref_type=heads

int main() {

	//SCOTCH_Num is the scotch integer type like INT32 or INT64
	//SCOTCH_Idx is the scotch memory index

	// scotch integer value
	SCOTCH_Num vertnumExemple;

	// scotch datastructure
	SCOTCH_Graph graphExemple;



	// Basic usage of scotch
	SCOTCH_Strat strat ; 
	SCOTCH_Graph graph ; 
	SCOTCH_Num baseval = 0 ; 
	SCOTCH_Num vertnbr = 6 ; // nombre de sommets
	SCOTCH_Num edgenbr = 12 ; // nombre d'aretes
	SCOTCH_Num partnbr = 3 ; // nombre de partitions souhaitées
	SCOTCH_Num verttab[] = {0,2,5,7,9,10,12};
	SCOTCH_Num edgetab[] = {1,3,0,2,4,1,5,0,5,1,2,3};

        SCOTCH_stratInit(&strat); //defaut strategy is used
        SCOTCH_graphInit(&graph);


	SCOTCH_graphBuild(
			&graph, 
			baseval,
			vertnbr,
			verttab,
			nullptr,
			nullptr,
			nullptr,
			edgenbr,
			edgetab,
			nullptr);
	SCOTCH_graphCheck(&graph);

	auto parttab = std::vector<SCOTCH_Num>(vertnbr) ; 
	SCOTCH_graphPart(&graph, partnbr, &strat, parttab.data()) ; 

	// show the partition

	std::cout << "Graph partitioning :" << std::endl;
	for (SCOTCH_Num i = 0; i < vertnbr; ++i) {
		std::cout << "vertice " << i << " -> Partition " << parttab[i] << std::endl;
	}

	SCOTCH_graphExit(&graph) ; 
	SCOTCH_stratExit(&strat) ; 

}

