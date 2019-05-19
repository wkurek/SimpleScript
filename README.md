# SimpleScript

Prosty język skryptowy bazowany na języku JavaScript i pozwalający na wykonywanie podzbioru jego instrukcji.

## Gramatyka

Specyfikacja gramatyki języka formlanego w [formacie EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form).
Gramatyka języka pozwala na wykonywanie operacji arytmetycznych (dodawanie, odejmowanie, mnożenie i dzielenie) oraz operacji logicznych (`AND`, `OR`, `NOT`). Wspierane są liczby całkowite oraz zmiennoprzecinkowe, zmienne typu Boolean oraz łańcuchy znaków. Dostępny jest operator przypisania, preinkrementacji jak i predekrementacji.
Istnieje mozliwość definicji zmiennych oraz funkcji z zachowaniem globalnego/lokalnego zakresu (`scope`).
Język umożliwia definiowanie obiektów w notacji zbliżonej do formatu JSON. Obiekty mogą zawierać inne obiekty oraz funkcje.
Gramatyka umożliwia wykonywanie instrukcji warunkowych `if/else`, dostepne są operatory warunkowe (`==`, `!=`, `<=`, `<`, `>`, `>=`).
Dostępna jest również instrukcja `while`.
Instrukcje muszą byc kończone średnikiem `;`.

W ramach języka zdefiniowana jest wbudowana, dostepna globalnie, funkcja `log()` pozwalająca na wyświetlanie danych w konsoli.

Istnieje możliwość wykorzystywanie komentarzy zarówno jedno jak i wieloliniowych.

[Zobacz całą gramatykę!](SimpleScript/SimpleScript.ebnf)

Lexer zakłada pomijanie znaków białych (`[ \t\n\r]`). W kontekście lexera pomijane są również komentarze, zarówno jedno jak i wieloliniowe.

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
  var sum = 4 + i;
  --i;
}

c = 12;

if (c < 14) {
  log("positive");
}

log(c);
```

## Wymagania

- Microsoft Visual Studio 2019
- googletest for Microsoft Visual Studio 2019
- [winflexbioson3](https://sourceforge.net/projects/winflexbison/files/winflexbison3-latest.zip/download)
- [Win flex-bison Microsoft Visual Studio 2019 setup](https://sourceforge.net/p/winflexbison/wiki/Visual%20Studio%20custom%20build%20rules/)
