#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{

MPI_Init(&argc, &argv);

printf("Hello World\n");

MPI_Finalize();

}
