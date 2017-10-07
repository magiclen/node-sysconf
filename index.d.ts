declare module "node-sysconf" {
    /**
     * Get the value of a specific system variable.
     * @param {number!} name For example: sysconf._SC_PAGE_SIZE
     * @returns {number | boolean} If the system variable is unavailable, it will return false.
     */
    export function get(name: number): number | boolean;
}
