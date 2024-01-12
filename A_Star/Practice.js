let ROW = 9;
let COL = 10;
// Source is the left-most bottom-most corner
let src = [8, 0];
 
// Destination is the left-most top-most corner
let dest = [0, 0];
 
class cell {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    constructor(){
        this.parent_i = 0;
        this.parent_j = 0;
        this.f = 0;
        this.g = 0;
        this.h = 0;
    }
}

const cellDetails = new Array(ROW);

for (let i = 0; i < ROW; i++) {
    cellDetails[i]  = new Array(COL);
}


let i, j;
 
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellDetails[i][j] = new cell();
            cellDetails[i][j].f = 2147483647;
            cellDetails[i][j].g = 2147483647;
            cellDetails[i][j].h = 2147483647;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }

    }

    i = src[0], j = src[1];
    cellDetails[i][j].f = 0;
    cellDetails[i][j].g = 0;
    cellDetails[i][j].h = 0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
//  console.log(cellDetails);


    // console.log(cellDetails[1][1].parent_i);
    // let closedList = new Array(ROW);
    // for(let i = 0; i < ROW; i++){
    //     closedList[i] = new Array(COL).fill(false);
    // }
    // console.log(closedList);
    
    // let openList = new Map()
    // openList.set(0, [i,j])
    // let p = openList.entries().next().value
    // console.log(openList, openList.size, p[1][0]);

    const Path = [
        [2, 3],
        [2, 4],
        [1, 4],
        [1, 5],
        [0, 5],
        [0, 6]
    ];
    // let p = Path[0];
    console.log(Path.shift());
    // while (Path.length > 0) {
    //     let p = Path[0];
    //     Path.shift();
        
    //     if (p[0] == 2 || p[0] == 1) {
    //         console.log("-> (" + p[0] + ", " + (p[1] - 1) + ")");
    //     } else {
    //         console.log("-> (" + p[0] + ", " + p[1] + ")");
    //     }
    // }
    