sysconf For Node.js
=================================

[![CI](https://github.com/magiclen/node-sysconf/actions/workflows/ci.yml/badge.svg)](https://github.com/magiclen/node-sysconf/actions/workflows/ci.yml)

## Usage

You can use `get` function to get the value of system variables.

```javascript
const result = sysconf.get(sysconf._SC_PAGE_SIZE); // 4096
```

## License

[MIT](LICENSE)
