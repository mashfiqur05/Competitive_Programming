// Linear Diophantine Equation Template
// Equation: a*x + b*y = c
//
// Main formula:
// If one solution is (x0, y0), then all solutions are:
// x = x0 + k * (b / g)
// y = y0 - k * (a / g)
// where g = gcd(a, b)

using ll = long long;

// Complexity: O(log(min(a, b)))
ll extendedGcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

// Finds one solution of a*x + b*y = c
// Complexity: O(log(min(a, b)))
bool findAnySolution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g)
{
    g = extendedGcd(abs(a), abs(b), x0, y0);

    if (c % g != 0)
        return false;

    x0 *= c / g;
    y0 *= c / g;

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return true;
}

// Shifts one solution to another solution
// x = x + cnt * b
// y = y - cnt * a
// Here a and b should already be divided by gcd
// Complexity: O(1)
void shiftSolution(ll &x, ll &y, ll a, ll b, ll cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

// Floor division that also works for negative values
// Complexity: O(1)
ll floorDiv(ll a, ll b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }

    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

// Ceil division that also works for negative values
// Complexity: O(1)
ll ceilDiv(ll a, ll b)
{
    if (b < 0)
    {
        a = -a;
        b = -b;
    }

    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}

// Updates valid k range for:
// low <= value + k * step <= high
// Complexity: O(1)
bool updateRange(ll value, ll step, ll low, ll high, ll &L, ll &R)
{
    if (step == 0)
    {
        return low <= value && value <= high;
    }

    ll l, r;

    if (step > 0)
    {
        l = ceilDiv(low - value, step);
        r = floorDiv(high - value, step);
    }
    else
    {
        l = ceilDiv(high - value, step);
        r = floorDiv(low - value, step);
    }

    L = max(L, l);
    R = min(R, r);

    return L <= R;
}

// Counts solutions of a*x + b*y = c
// where:
// minx <= x <= maxx
// miny <= y <= maxy
//
// Complexity: O(log(min(a, b)))
ll countSolutionsInRange(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    if (minx > maxx || miny > maxy)
        return 0;

    // Case: 0*x + 0*y = c
    // Complexity: O(1)
    if (a == 0 && b == 0)
    {
        if (c != 0) return 0;
        return (maxx - minx + 1) * (maxy - miny + 1);
    }

    // Case: 0*x + b*y = c
    // Complexity: O(1)
    if (a == 0)
    {
        if (c % b != 0) return 0;

        ll y = c / b;

        if (y < miny || y > maxy) return 0;

        return maxx - minx + 1;
    }

    // Case: a*x + 0*y = c
    // Complexity: O(1)
    if (b == 0)
    {
        if (c % a != 0) return 0;

        ll x = c / a;

        if (x < minx || x > maxx) return 0;

        return maxy - miny + 1;
    }

    ll x0, y0, g;

    // Complexity: O(log(min(a, b)))
    if (!findAnySolution(a, b, c, x0, y0, g))
        return 0;

    // General solution:
    // x = x0 + k * (b / g)
    // y = y0 - k * (a / g)

    ll dx = b / g;
    ll dy = -a / g;

    ll L = -4e18;
    ll R = 4e18;

    // Restrict x inside [minx, maxx]
    // Complexity: O(1)
    if (!updateRange(x0, dx, minx, maxx, L, R))
        return 0;

    // Restrict y inside [miny, maxy]
    // Complexity: O(1)
    if (!updateRange(y0, dy, miny, maxy, L, R))
        return 0;

    return R - L + 1;
}

// Counts non-negative solutions of:
// a*x + b*y = c
// where x >= 0 and y >= 0
//
// Complexity: O(log(min(a, b)))
ll countNonNegativeSolutions(ll a, ll b, ll c)
{
    const ll INF = 4e18;

    return countSolutionsInRange(a, b, c, 0, INF, 0, INF);
}

// Gets all solutions inside range
// Use only when number of solutions is small
//
// Let number of valid solutions be K.
// Complexity: O(log(min(a, b)) + K)
vector<pair<ll, ll>> getAllSolutionsInRange(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    vector<pair<ll, ll>> solutions;

    if (a == 0 || b == 0)
    {
        // This function is mainly for normal case where both a and b are non-zero.
        // For a == 0 or b == 0, handle separately if needed.
        return solutions;
    }

    ll x0, y0, g;

    // Complexity: O(log(min(a, b)))
    if (!findAnySolution(a, b, c, x0, y0, g))
        return solutions;

    ll dx = b / g;
    ll dy = -a / g;

    ll L = -4e18;
    ll R = 4e18;

    // Complexity: O(1)
    if (!updateRange(x0, dx, minx, maxx, L, R))
        return solutions;

    // Complexity: O(1)
    if (!updateRange(y0, dy, miny, maxy, L, R))
        return solutions;

    // Complexity: O(K)
    for (ll k = L; k <= R; k++)
    {
        ll x = x0 + k * dx;
        ll y = y0 + k * dy;

        solutions.push_back({x, y});
    }

    return solutions;
}