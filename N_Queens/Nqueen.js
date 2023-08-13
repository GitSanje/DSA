function NQueenProblem(N) {
    let board = new Array(N).fill(0).map(() => new Array(N).fill(0));
    let queens = [];
    function N_QueenPrblm(board, row) {
      if (row === N) return true;
  
      for (let col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
          board[row][col] = 1;
          queens.push({ row, col }); // Track placed queens
  
          if (N_QueenPrblm(board, row + 1)) return true;
  
          board[row][col] = 0;
          queens.pop(); // Remove unplaced queens
        }
      }
  
      return false;
    }
  
    function isSafe(board, row, col) {
      // Check upper-vertical
      for (let i = row; i >= 0; i--) {
        if (board[i][col] === 1) {
          return false;
        }
      }
  
      // Check upper-left diagonal
      let j = col;
      for (let i = row; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] === 1) {
          return false;
        }
      }
  
      // Check upper-right diagonal
      j = col;
      for (let i = row; i >= 0 && j < N; i--, j++) {
        if (board[i][j] === 1) {
          return false;
        }
      }
  
      return true;
    }
  
    // if (N_QueenPrblm(board, 0)) {
    //   let solutionOutput = "";
    //   solutionOutput += "Solution exists. Placing the queens:\n";
    //   for (let i = 0; i < N; i++) {
    //     solutionOutput += board[i].join(" ") + "\n";
    //   }
    //   return solutionOutput;
    // } else {
    //   return "No solution exists for N = " + N;
    // }

    
  const startTime = performance.now();
  const solutionExists = N_QueenPrblm(board, 0);
  const endTime = performance.now();
  const executionTime = endTime - startTime;

  return {
    solutionExists,
    executionTime,
    board,
    queens
  };


  }
  
  function solveNQueen() {
    const inputN = document.getElementById("inputN");
    const solutionOutput = document.getElementById("solutionOutput");
    const executionTime = document.getElementById("executionTime");
    const queensCount = document.getElementById("queensCount");
    // const solveButton = document.getElementById("solve");
    const N = parseInt(inputN.value);
     //const solution = NQueenProblem(N);
     //solutionOutput.textContent = solution;

    if (N >= 4 && N <= 29) {
        const { solutionExists, executionTime: time ,board,queens} = NQueenProblem(N);
        if (solutionExists) {
            let boardOutput = "";
            for (let i = 0; i < N; i++) {
              boardOutput += board[i].join(" ") + "\n";
            }
            solutionOutput.textContent = "Solution exists. Placing the queens:\n" + boardOutput;

                    const chessboard = document.getElementById("solvechessboard");
              chessboard.innerHTML = "";
              chessboard.style.gridTemplateColumns = `repeat(${N}, 1fr)`;
              chessboard.style.gridTemplateRows = `repeat(${N}, 1fr)`;

              for (let row = 0; row < N; row++) {
                for (let col = 0; col < N; col++) {
                  const square = document.createElement("div");

                  square.classList.add("Sqr");
                  square.id = `square-${row}-${col}`;

                  if (board[row][col] === 1) {

                    if ((row + col) % 2 === 0) {
                      square.style.backgroundColor = "#eee";
                      
                    } else {
                      square.style.backgroundColor = "#ccc";
                    
                    }
                    
                    square.innerHTML = '<i class="fas fa-chess-queen"></i>';
                    square.classList.add("queen");
                  } 
                  if ((row + col) % 2 === 0) {
                    square.style.backgroundColor = "#eee";
                    
                  } else {
                    square.style.backgroundColor = "#ccc";
                  
                  }
                   
                  chessboard.appendChild(square);
                }
              }


          } else {
            solutionOutput.textContent = "No solution exists for N = " ;
          }

          executionTime.textContent = "Execution time: " + time.toFixed(2) + " milliseconds";
          queensCount.textContent = "Queens: " + queens.length;

    }

    else {
        solutionOutput.textContent = "Please enter a value between 4 and 29.";
        executionTime.textContent = "";
      }
  }
  