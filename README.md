# SimpleScript :page_with_curl:
Celem projektu było stworzenie prostego języka skryptowego bazowanego na języku JavaScript i pozwalającego na wykonywanie podzbioru jego instrukcji. W ramach projektu została stworzona gramatyka a następnie na jej podstawie został wytworzony lexer, parser oraz interpreter języka.
Gramatyka języka jest zdefiniowana w formacie ENBF.
W projekcie do generacji lexera i parsera zostały wykorzystane zewnętrze narzędzia: Flex oraz Bison. Narzędzia te na podstawie plików konfiguracyjnych generowały odpowiednio lexer oraz parser. Pliki konfiguracyjne były tworzone na postawie sformułowanej wcześniej w formacie EBNF  gramatyki.
Do testów jednostkowych została wykorzystana technologia GoogleTest. Testami zostały pokryte węzły drzewa AST, generowanego przez parser, połączenia i interakcje pomiędzy poszczególnymi węzłami w ich hierarchii. Testy jednostkowe pokrywają również wygenerowany lexer oraz parser.

## Gramatyka :abc:
Specyfikacja gramatyki języka formlanego została sformułowana w formacie [formacie EBNF](https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form). 
Gramatyka języka pozwala na wykonywanie operacji arytmetycznych (dodawanie, odejmowanie, mnożenie i dzielenie) oraz operacji logicznych (AND, OR, NOT). Wspierane są liczby całkowite oraz zmiennoprzecinkowe, zmienne typu Boolean oraz łańcuchy znaków. 
Dostępny jest operator przypisania, preinkrementacji jak i predekrementacji. Istnieje mozliwość definicji zmiennych oraz funkcji z zachowaniem globalnego/lokalnego zakresu (scope). 
Język umożliwia definiowanie obiektów w notacji zbliżonej do formatu JSON. 
Obiekty mogą zawierać inne, zagnieżdżone, obiekty, funkcje oraz wartości prymitywne. Gramatyka umożliwia wykonywanie instrukcji warunkowych `if`/`else`, dostepne są operatory porównania (`==`, `!=`, `<=`, `<`, `>`, `>=`). Dostępna jest również instrukcja Chile, pozwalająca na definiowanie pętli. 

Instrukcje, w przeciwieństwie do języka JavaScript, zawsze muszą być kończone średnikiem `;`.

W ramach języka zdefiniowana jest wbudowana, dostępna globalnie, funkcja `log()` pozwalająca na wyświetlanie danych w konsoli (jednoargumentowy odpowiednik `console.log()` z JavaScript).
Istnieje możliwość wykorzystywania komentarzy zarówno jedno jak i wieloliniowych.
Lexer zakłada pomijanie znaków białych (`[ \t\n\r]`). W kontekście lexera pomijane są również komentarze, zarówno jedno jak i wieloliniowe.

[Zobacz całą gramatykę!](SimpleScript/SimpleScript.ebnf)

## Drzewo AST :deciduous_tree:
Podstawowym i najważniejszym węzłem w całym drzewie jest węzeł klasy `Program`. Węzeł ten stanowi obudowanie listy instrukcji i jest reprezentacją całego programu. Przez jego interface jest rozpoczynane interpretowanie wszystkich instrukcji. Zawiera on listę węzłów klasy `Statement`, stanowiącej interface dla wszystkich instrukcji najwyższego poziomu. Węzeł klasy program w ramach swojego wykonywania jest odpowiedzialny za stworzenie obiektu klasy Object reprezentującego global scope, wygenerowanie globalnie dostępnych funkcji bibliotecznych (tutaj funkcja `log()`) oraz rozpoczęcie wykonywania każdej z instrukcji wchodzących w skład programu w kolejności ich występowania. W ramach języka nie jest dostępny mechanizm hostingu dostępny w JavaScript.
Instrukcje są wykonywane przez wywołanie na nich funkcji `evaluate()` przyjmującej jako argument referencję na obiekt klasy `Object` reprezentujący global scope. 
Instrukcje dzielą wspólny interface Statement. Konkretyzacją tego interface są klasy: `ConditionalStatement`, `IterationStatement`, `ReturnStatement`, `FunctionDeclarationStatement`, `ExpressionStatement`, `VariableDeclarationStatement`.
Wyrażenia dziedziczą po wspólnym interface `OperationExpression` zwierającym funkcję `evaluate()` przyjmująca jako argument referencję na obiekt klasy Object reprezentujący scope w ramach którego dane wyrażenie ma być ewaluowane. Wyrażeniem są wszystkie operacje logiczne i arytmetyczne zarówno wieloargumentowe jak i jednoargumentowe. Operacje przypisania są również wyrażeniem. Jako wyrażenie uznajemy tutaj również wywołanie funkcji. Wyrażenia charakteryzują się tym, że w wyniku swojej ewaluacji zwracają wartość (w postaci obiektu klasy `Variable`).  Jako wyrażenie traktujemy również zmienne oraz stałe w kontekście, w którym potrzebujemy ich wartości.
Wyrażenia są wykorzystywane m.in. jako warunki w `if`/`else` czy `while`.
Klasa Variable reprezentuje ogólnie pojętą wartość. Zaimplementowana jest w postaci „kontenera” na typy: `Object`, `Function` oraz `Primitive`. Zawiera prywatną zmienną, w której przechowywany jest aktualny typ wartości. Klasa ta przeciąża wiele operatorów arytmetycznych jak i logicznych.
Klasa Primitive jest „kontenerem” na typy prymitywne. Jako typy prymitywne rozumiemy tutaj: `Integer`, `Float`, `Boolean`, `String`. Klasa ta przeciąża wiele operatorów arytmetycznych jak i logicznych.
Klasa `Object` reprezentuje obiekt. Zawiera w sobie trzy mapy: mapę obiektów (`Object`), mapę funkcji (`Function`) oraz mapę prymitywów (`Primitive`) z uwagi na to, że obiekt może zawierać w sobie właściwości tych typów. Zdefiniowane zostały funkcje umożliwiające dodawanie nowych właściwości do obiektów jak i ich usuwanie oraz pobieranie.
Klasa `Function` reprezentuje funkcje i zawiera w sobie listę parametrów oraz listę potencjalnych przyszłych argumentów, które podczas ewaluacji będą zmapowane na parametry. W ramach ewaluacji funkcja zwraca obiekt typu `Variable`. Podczas ewaluacji funkcja tworzy swój własny, wyizolowany scope, w którym przekazane do funkcji argumenty zmapowane są na występujące w deklaracji funkcji parametry.
Istnieje możliwość definiowania funkcji anonimowych, jednak często chcemy nadać im nazwy by móc się do nich odwołać. Nazwy funkcji tak samo jak i wszystkich innych zmiennych są reprezentowane przez obiekt klasy `Identifier`. Obiekt ten wewnętrznie zawiera listę łańcuchów znakowych `String` i definiuje operatory dostępu do głowy oraz ogona listy łańcuchów znakowych. Operatory te umożliwiają używanie zagnieżdżonych, wielopoziomowych nazw zmiennych.
W przypadku błędów przy ewaluacji programu rzucane są wyjątki dziedziczące po klasie bazowej ParseException udastępnijącej metodę `what()`. Wyróżniamy nastepujące typy wyjątków: `InvalidIdentifierException`, `ParameterMismatchExceptio`, `UndefinedFunctionException`, `ZeroDivisionException`.

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

## Uruchamianie programu :arrow_forward:
Program uruchamiamy przekazując mu ścieżkę do pliku z kodem do zinterpretowania.
```
$ SimpleScript <file_path>
```

## Wymagania

- Microsoft Visual Studio 2019
- googletest for Microsoft Visual Studio 2019
- [winflexbioson3](https://sourceforge.net/projects/winflexbison/files/winflexbison3-latest.zip/download)
- [Win flex-bison Microsoft Visual Studio 2019 setup](https://sourceforge.net/p/winflexbison/wiki/Visual%20Studio%20custom%20build%20rules/)