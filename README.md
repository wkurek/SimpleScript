# SimpleScript
Prosty język skryptowy bazowany na języku JavaScript.

## Gramatyka
Specyfikacja gramatyki języka formlanego w [formacie EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form).
Gramatyka języka pozwala na użycie wykonywanie prostych operacji arytmetycznych oraz logicznych. Możliwe jest definiowanie i wykonywanie funkcji. Język umożliwia definiowanie obiektów w notacji zbliżonej do formatu JSON.

[Zobacz gramatykę!](SimpleScript/SimpleScript.ebnf)

Lexer zakłada pomijanie znaków białych oraz średnika (`[ \t\n\r;]`). Pomijane są również komentarze, zarówno jedno jak i wieloliniowe.

## Przykłady użycia
```
var a = 1,
  b,
  c = false;

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
  var sum = 4 + 10;
  --i;
}
```

