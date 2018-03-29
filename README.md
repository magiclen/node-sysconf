sysconf For Node.js
=================================

## Introduction

Get configurable system variables.

## Installation

Run `npm i` or `npm install` to install.

```bash
npm install node-sysconf
```

If you want to save this module to package.json, please add `--save` option.

```bash
npm install node-sysconf --save
```

## Initialization

Import this module by using `require` function.

```javascript
const sysconf = require('node-sysconf');
```

## Usage

You can use `get` function to get the value of system variables.

```javascript
var result = sysconf.get(sysconf._SC_PAGE_SIZE); // 4096
```

## Tests

To run the test suite, first install the dependencies, then run `npm test`:

```bash
npm install
npm test
```

## License

[MIT](LICENSE)
