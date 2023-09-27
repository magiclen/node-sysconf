sysconf For Node.js
=================================

[![CI](https://github.com/magiclen/node-sysconf/actions/workflows/ci.yml/badge.svg)](https://github.com/magiclen/node-sysconf/actions/workflows/ci.yml)

Get configurable system variables.

You need to set up the Rust development environment: [rustup](https://rustup.rs/)

## Usage

You can use `sysconf` function to get the value of system variables.

```typescript
import { sysconf, _SC_PAGE_SIZE } from "node-sysconf";

const result = sysconf(_SC_PAGE_SIZE); // 4096
```

## License

[MIT](LICENSE)
