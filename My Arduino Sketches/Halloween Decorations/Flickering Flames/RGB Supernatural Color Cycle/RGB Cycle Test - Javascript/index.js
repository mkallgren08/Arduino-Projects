let r= 127;
let g= 255;
let b= 0;

let counter = 0;
let delay = 1000;

let rDir = "increase";
let gDir = "hold";
let bDir = "hold";
let overallDir = "forward"

$(document).ready(function(){
  console.log("Scripts loaded");

  // let r= 103;
  // let g= 255;
  // let b= 0;

  setTimeout(function(){
    console.log((delay/1000) + " seconds have passed")
    setInterval(function(){cycleThrough(r,g,b)}, 10);
  },delay)

});

function cycleThrough (){



  // let timenow = millis();
  if (r ==  127 && g ==  255 && b== 0 && overallDir ==  "forward"){
    rDir = "decrease"; gDir = "hold"; bDir = "hold";
  } else if (r== 0 && g ==  255 && b ==  0  && overallDir ==  "forward"){
    rDir = "hold"; bDir = "increase"
  } else if (r== 0 && g ==  255 && b ==  255  && overallDir ==  "forward"){
    gDir = "decrease"; bDir = "hold"
  } else if (r== 0 && g== 0 && b== 255  && overallDir ==  "forward"){
    rDir = "increase"; gDir = "hold";
  } else if (r ==  180 && g ==  0 && b== 255  && overallDir ==  "forward"){
    rDir = "decrease"; overallDir = "back";
  } else if (r ==  0 && g ==  0 && b ==  255 && overallDir == "back"){
    rDir = "hold"; gDir = "increase";
  } else if (r ==  0 && g ==  255 && b ==  255 && overallDir == "back"){
    gDir = "hold"; bDir = "decrease";
  } else if (r ==  0 && g ==  255 && b ==  0 && overallDir == "back"){
    rDir = "increase"; bDir = "hold";
  } else if (r == 126 && g == 255 && b == 0 && overallDir == "back"){
    overallDir = "forward"
  }
  // if (r===0){
  //   rDir = "increase";
  //   console.log(rDir);
  // };

  if (rDir == "increase"){r += 1;} else if (rDir != "hold"){r -= 1;};
  if (gDir == "increase"){g += 1;} else if (gDir != "hold"){g -= 1;};
  if (bDir == "increase"){b += 1;} else if (bDir != "hold"){b -= 1;};

    // if ( g < green || g === 0) {g += 1};
    // if ( g > green || g === 255 ) {g -= 1};

    // if ( b < blue || b === 0) {b += 1};
    // if ( b > blue || b === 255) {b -= 1};
    if (r%10 === 0){
      console.log(r + ", " + g + ", " +b);
    };
    $('.sampleDiv').attr('style','background-color:rgb('+r+","+g+","+b+")");
    
  
};


// Notes:
// GBIV spectrum is between rgb(127,255,0) and rgb(127,0,255)