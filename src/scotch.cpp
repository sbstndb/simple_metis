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
	SCOTCH_Strat strat; 
	// different strats : 
		// Glogab flags :
		//	-	SCOTCH_STRATDEFAULT
		//	-	SCOTCH_STRATBALANCE 	-- enforce load balance
		//	-	SCOTCH_STRATQUALITY 	-- privilege quality over speed
		//	-	SCOTCH_STRATSAFETY	-- avoid fpe
		//	-	SCOTCH_STRATSPEED	-- privilege speed over quality
		// Partitioning flags :
		//	-	SCOTCH_STRATRECURSIVE	-- use recursive bipartitioning methods and not direct kway methods
		//	-	SCOTCH_STRATREMAP	-- use the strategy for rzmmaping an existing partition
	SCOTCH_Graph graph ; 
	SCOTCH_Num baseval = 0 ; 
	SCOTCH_Num vertnbr = 6 ; // nombre de sommets
	SCOTCH_Num edgenbr = 12 ; // nombre d'aretes
	SCOTCH_Num partnbr = 3 ; // nombre de partitions souhaitées
	SCOTCH_Num verttab[] = {0,2,5,7,9,10,12};
	SCOTCH_Num edgetab[] = {1,3,0,2,4,1,5,0,5,1,2,3};

        SCOTCH_stratInit(&strat); //defaut strategy is used
        SCOTCH_graphInit(&graph);

	// Fill the source graph
	SCOTCH_graphBuild(
			&graph, 
			baseval,	// graph based value for index arrays
			vertnbr,	// number of vertices
			verttab,	// adjacency index array, of size (vertnbr+1)
			nullptr,	// adjacency end index array, of size (vertnbr) -- optional
			nullptr,	// vertex load array, of size (vertnbr) -- optional
			nullptr,	// vertex label array, of size (vertnbr) -- optional
			edgenbr,	// the number of arcs (twice the number of edges)
			edgetab,	// adjacency array, of size at least (edgenbr)
			nullptr);	// arc load array, of size (edgenbr) -- optional
	SCOTCH_graphCheck(&graph);

	auto parttab = std::vector<SCOTCH_Num>(vertnbr) ; 
	SCOTCH_graphPart(&graph, partnbr, &strat, parttab.data()) ; 

	std::cout << "Graph partitioning :" << std::endl;
	for (SCOTCH_Num i = 0; i < vertnbr; ++i) {
		std::cout << "vertice " << i << " -> Partition " << parttab[i] << std::endl;
	}

	SCOTCH_graphExit(&graph) ; 
	SCOTCH_stratExit(&strat) ;	// free the content of strat

	return 0 ;

}

