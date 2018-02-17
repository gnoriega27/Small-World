# COMP 345 – Small World
----

## Setup

### Standard install via command-line

```
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/Small-World
```

### Using npm / yarn

If you have npm and node installed on your machine, you can simply run:

```
yarn
yarn build
yarn test
```

## Architecture

The entirety of the architecture design was front-loaded as to reduce future time
investment in redesigning and refactoring the codebase as we include more requirements.

**You can find the class diagram for the entire project (minus the user interface) in /docs/class.png.**

The architecture aims to use all of the power and flexibility of C++ by leveraging
both OOP and functional programming techniques. This means that some units of compilation
are purely functional, while some others are purely OOP, and some are in between.
This also means that the whole architecture aims for [functional purity](https://en.wikipedia.org/wiki/Pure_function) and
[immutability]()
(see [here](https://hackernoon.com/5-benefits-of-immutable-objects-worth-considering-for-your-next-project-f98e7e85b6ac), and
[here](http://www.yegor256.com/2014/06/09/objects-should-be-immutable.html)
about why immutable objects are a cool thing).

The whole architecture revolves around two major design patterns: the first is centralized,
immutable state, and the second is a Mediator (Publisher/Subscriber) pattern that
bridges the gap between the (view) and the domain logic (controller).

Following the pioneers in complex user interface data flow, we opted for a React-Redux
like implementation of the MVC (MVVM) design pattern to handle the link between the View and
the Model. Both Redux and Vuex have excellent explanations
(see Redux [here](https://redux.js.org/docs/faq/ImmutableData.html), Vuex [here](https://vuex.vuejs.org/en/intro.html)) as to why having a
centralized, immutable store makes the whole interface much easier to program than
the classical MVC+Observer pattern.

Once again, the Pub/Sub implementation we have chosen is one that comes straight
from the JS userland, with the EventEmitter being a staple of the NodeJS core API.


## Notes on the Assignment

### Assignment 1

**Race Banners**

Race abilities are not implemented as pieces; rather they are implemented as a
Strategy pattern that belongs to the Race class. As such, there is no "physical"
implementation of the race abilities and the powers as pieces. Rather, the race
abilities and powers are defined as strategies (Strategy pattern). These
strategies are then implemented by concrete strategy classes (the empty blocks in the
domain::ability package). Actual pieces for powers and abilities will only be
implemented as part of the user interface.

**Map JSON Validation**

Albeit the JSON validator is not ready yet, you can find both a tentative map file
format (JSON) and the JSON Schema draft-04/06/07 map validation schema in the docs folder.

## Acknowledgements

This repository is based off @dpiet [C++ Boilerplate](https://github.com/dpiet/cpp-boilerplate)
