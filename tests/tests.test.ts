import { sysconf, _SC_PAGE_SIZE } from "../src/lib.js";

describe("Page Size", function () {
    it("should get the page size", function () {
        const result = sysconf(_SC_PAGE_SIZE);

        expect(result).not.toBe(-1);
    });
});
