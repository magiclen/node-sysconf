import { _SC_PAGE_SIZE, sysconf } from "../src/lib.js";

describe("Page Size", () => {
    it("should get the page size", () => {
        const result = sysconf(_SC_PAGE_SIZE);

        expect(result).not.toBe(-1);
    });
});
