#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
   int rank, n_ranks, next_rank, prev_rank;
   char send_message[50];  // Array to hold the message to be sent
   char recv_message[50];  // Array to hold the received message
   MPI_Status status;

   // First call MPI_Init
   MPI_Init(&argc, &argv);

   // Get my rank and the number of ranks
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);

   // Check that we have at least 2 ranks
   if (n_ranks < 2) {
        printf("This example requires at least two ranks\n");
        MPI_Finalize();
        return(1);
   }

   // Determine the next and previous ranks in a circular communication pattern
   next_rank = (rank + 1) % n_ranks;  // Rank after the current one (circular)
   prev_rank = (rank - 1 + n_ranks) % n_ranks;  // Rank before the current one (circular)

   // Set the message to be sent
   sprintf(send_message, "Message from rank %d", rank);  // Create a message that includes rank number

   // Send message to the next rank and receive from the previous rank
   MPI_Send(send_message, strlen(send_message) + 1, MPI_CHAR, next_rank, 0, MPI_COMM_WORLD);
   MPI_Recv(recv_message, 50, MPI_CHAR, prev_rank, 0, MPI_COMM_WORLD, &status);

   // Print the received message
   printf("Rank %d received message: '%s'\n", rank, recv_message);

   // Call finalize at the end
   MPI_Finalize();

   return 0;
}
