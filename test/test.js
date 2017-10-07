'use strict';

const expect = require('chai').expect;

const sysconf = require('../index');

describe('Page Size', function() {
  it('should get the page size', function() {
    var result = sysconf.get(sysconf._SC_PAGE_SIZE);
    expect(result).to.not.equal(false);
  });
});
