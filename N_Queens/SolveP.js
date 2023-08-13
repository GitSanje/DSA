function createChessboard2(n) {
    const chessboard = document.getElementById("solvechessboard");
    chessboard.innerHTML = "";
  
    chessboard.style.gridTemplateColumns = `repeat(${n}, 1fr)`;
    chessboard.style.gridTemplateRows = `repeat(${n}, 1fr)`;
  
    for (let row = 0; row < n; row++) {
      for (let col = 0; col < n; col++) {
        const square = document.createElement("div");
  
        square.classList.add("Sqr");
        square.id = `square-${row}-${col}`;
  
        if ((row + col) % 2 === 0) {
          square.style.backgroundColor = "#eee";
        } else {
          square.style.backgroundColor = "#ccc";
        }
  
        chessboard.appendChild(square);
      }
    }
  }
  


  const inputN = document.getElementById("inputN");
  const solveButton = document.getElementById("solve");


  //document.addEventListener("DOMContentLoaded", function() {
   
    solveButton.addEventListener("click", () => {
        N = parseInt(inputN.value);
        createChessboard2(N);
      });
  //});
  
  