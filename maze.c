#include<string.h>
#include<stdio.h>

int isFree(char maze[][5], int i, int j) {
  return maze[i][j] == ' ';
}

int bfs(char maze[][5], int rows, int visited[][5], int i, int j) {
  
  while((i > 0 && i < rows) && (j > 0 && j < strlen(maze[0]))) {
    if(isFree(maze, i+1, j) && visited[i+1][j] == 0) {
      visited[i+1][j] = 1;
      printf("nach unten \n");
      i++;
    }
    else if(isFree(maze, i, j+1) && visited[i][j+1] == 0) {
      visited[i][j+1] = 1;
      printf("nach rechts \n");
      j++;
    }
    else if(isFree(maze, i-1, j) && visited[i-1][j] == 0) {
      visited[i-1][j] = 1;
      printf("nach oben \n");
      i--;
    }
    else if(isFree(maze, i, j-1) && visited[i][j-1] == 0) {
      visited[i][j-1] = 1;
      printf("nach links \n");
      j--;
    }
    else { 
      return 0;
    }
  }
  
  if(isFree(maze, i, j)) {
    return 1;
  }
  return 0;
}

int hasExit(char maze[][5], int visited[][5], int rows) {
  int boolean;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < strlen(maze[0]); j++) {
      if(maze[i][j] == 'k') {
        boolean = bfs(maze, rows, visited, i, j);
        return boolean;
      }
    }
  }
  return boolean;
}


int main() {
  
  char maze[3][5];
  int visited[3][5] = {0};

  strcpy(maze[0], "# ##");
  strcpy(maze[1], "# k#");
  strcpy(maze[2], "####");
  
  int boolean = hasExit(maze, visited, 3);
  if(boolean == 1) 
    printf("%s \n", "I'm OUT!!"); 
  else 
    printf("%s \n", "There is no exit!");
}
