function createQueenList(n) {
  const queenListElement = document.getElementById("queens");
  queenListElement.innerHTML = "";

  for (let i = 0; i < n; i++) {
    const queenItem = document.createElement("li");
    queenItem.innerHTML = `<i class="fas fa-chess-queen"></i>`;
    queenListElement.appendChild(queenItem);
  }
}

function updateQueenList(queens, totalQueens) {
  const queenListElement = document.getElementById("queens");
  const placedQueens = queens.length;
  const unplacedQueens = totalQueens - placedQueens;

  queenListElement.innerHTML = "";

  for (let i = 0; i < unplacedQueens; i++) {
    const queenItem = document.createElement("li");
    queenItem.innerHTML = `<i class="fas fa-chess-queen"></i>`;
    queenListElement.appendChild(queenItem);
  }
}

function createChessboard(n) {
  const chessboard = document.getElementById("chessboard");
  chessboard.innerHTML = "";

  chessboard.style.gridTemplateColumns = `repeat(${n}, 1fr)`;
  chessboard.style.gridTemplateRows = `repeat(${n}, 1fr)`;
  const queens = []; // Array to store queen positions

  createQueenList(n);

  for (let row = 0; row < n; row++) {
    for (let col = 0; col < n; col++) {
      const square = document.createElement("div");

      square.classList.add("square");
      square.id = `square-${row}-${col}`;

      if ((row + col) % 2 === 0) {
        square.style.backgroundColor = "#eee";
      } else {
        square.style.backgroundColor = "#ccc";
      }

      square.addEventListener("click", () => {
        if (queens.length < n) {
          const queenIndex = queens.findIndex(
            (queen) => queen.row === row && queen.col === col
          );
    
          if (queenIndex >= 0) {
            queens.splice(queenIndex, 1);
            console.log(queens);
            square.innerHTML = "";
            square.classList.remove("queen");
          }
          if (!isSquareAttacked(row, col, queens)) {
            if (queenIndex === -1) {
              queens.push({ row, col });
              square.innerHTML = '<i class="fas fa-chess-queen"></i>';
              square.classList.add("queen");
            }

            //  console.log(queens,n, queens.length);
            updateQueenList(queens, n);
            updateQueenCount(queens.length);
            highlightAttackedSquares(queens);
          }
        }

        if (queens.length == n) {
          const win = document.getElementById("queenList");
          win.textContent = "You won the game";
        }
      });

      square.addEventListener("mouseover", () => {
        if (!isSquareAttacked(row, col, queens)) {
          square.classList.add("hover");
          highlightAttackedSquares(queens, row, col);
        }
      });

      square.addEventListener("mouseout", () => {
        square.classList.remove("hover");
        highlightAttackedSquares(queens);
      });

      chessboard.appendChild(square);
    }
  }
}

function updateQueenCount(count) {
  const queenCountElement = document.getElementById("queenCount");
  queenCountElement.textContent = `Queens Placed: ${count}`;
}

function isSquareAttacked(row, col, queens) {
  return queens.some((queen) =>
    isRowColumnOrDiagonalAttack(row, col, queen.row, queen.col)
  );
}

function isRowColumnOrDiagonalAttack(row1, col1, row2, col2) {
  return (
    row1 === row2 ||
    col1 === col2 ||
    Math.abs(row1 - row2) === Math.abs(col1 - col2)
  );
}
function highlightAttackedSquares(queens, hoverRow, hoverCol) {
  const squares = document.getElementsByClassName("square");

  for (const square of squares) {
    square.classList.remove(
      "attacked-row",
      "attacked-column",
      "attacked-diagonal",
      "hover"
    );

    const [currRow, currCol] = square.id.split("-").slice(1).map(Number);

    let isSquareAttacked = false;

    for (const queen of queens) {
      const { row, col } = queen;
      console.log(queen);

      if (
        currRow === row ||
        currCol === col ||
        Math.abs(currRow - row) === Math.abs(currCol - col)
      ) {
        if (currRow === row) {
          square.classList.add("attacked-row");
          isSquareAttacked = true;
        }

        if (currCol === col) {
          square.classList.add("attacked-column");
          isSquareAttacked = true;
        }

        if (Math.abs(currRow - row) === Math.abs(currCol - col)) {
          square.classList.add("attacked-diagonal");
          isSquareAttacked = true;
        }
      }
    }

    if (currRow === hoverRow || currCol === hoverCol) {
      square.classList.add("hover");
    }

    if (!isSquareAttacked && (currRow !== hoverRow || currCol !== hoverCol)) {
      square.classList.add("unattacked");
    }
  }
}

const boardSize = document.getElementById("boardSize");
const createButton = document.getElementById("create");
let N = parseInt(boardSize.value) || 8;


createButton.addEventListener("click", () => {
  N = parseInt(boardSize.value);
  createChessboard(N);
});

// Call createChessboard function with the default value on page load
createChessboard(N);
