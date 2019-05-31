y = 12.345345;
b12;

return y;

log(y);

var a = 1,
  b,
  c = false;


function funct(a, b) {
  if(a > b && b <= 99) return a+ b;
  else if (b > 99) return "napis";
  else return 777;
}


// dummy function
function math(x, y, z) {
  if (x >= y && z) {
    return x + y;
  } else {
    var k = x / y;
    return z * k;
  }
}

b = 2 * (6 - 5);
var c = math(a, b, false);

var object = {
  property: "abcd",
  act: function(a) {
    return a * 2;
  }
};
/*
    multiple line comment
*/
object["property"] = object.act(2 * 4);

var i = 12;
while (i > 0) {
  var sum = 4 + i;
  --i;
}

c = 12;

if (c < 14) {
  log("positive");
}

log(c);

log(funct(12, 9));
log(funct(12, 890));
log(funct(12, 15));
