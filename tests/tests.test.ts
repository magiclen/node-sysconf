import { describe, it } from "mocha";
import { expect } from "chai";

import * as sysconf from "..";

describe("Page Size", function () {
    it("should get the page size", function () {
        const result = sysconf.get(sysconf.Name._SC_PAGE_SIZE);
        expect(result).to.not.equal(undefined);
    });
});
