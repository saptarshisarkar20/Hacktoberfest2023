from collections import defaultdict

def minimumDualArea(points, n):
    if n < 2:
        return 0
    
    xmap, ymap = defaultdict(list), defaultdict(list)
    for point in points:
        x, y = point
        xmap[x].append(point)
        ymap[y].append(point)

    for key_ in xmap:
        xmap[key_].sort(key = lambda point: point[1])
    for key_ in ymap:
        ymap[key_].sort(key = lambda point: point[0])
    
    xvalues = sorted(xmap.keys())
    yvalues = sorted(ymap.keys())
    nx, ny = len(xvalues), len(yvalues)
    
    # make rectangles in x direction
    yminLeft = [float('inf') for i_ in range(nx)]
    ymaxLeft = [float('-inf') for i_ in range(nx)]
    
    yminRight = [float('inf') for i_ in range(nx)]
    ymaxRight = [float('-inf') for i_ in range(nx)]
    
    ymin, ymax = float('inf'), float('-inf')
    for i in range(nx):
        xvalue = xvalues[i]
        ymin = min(ymin, xmap[xvalue][0][1])
        ymax = max(ymax, xmap[xvalue][-1][1])
        yminLeft[i] = ymin
        ymaxLeft[i] = ymax
    
    ymin, ymax = float('inf'), float('-inf')
    for i in range(nx)[::-1]:
        xvalue = xvalues[i]
        ymin = min(ymin, xmap[xvalue][0][1])
        ymax = max(ymax, xmap[xvalue][-1][1])
        yminRight[i] = ymin
        ymaxRight[i] = ymax
    
    
    # make rectangles in y direction
    xminBottom = [float('inf') for i_ in range(ny)]
    xmaxBottom = [float('-inf') for i_ in range(ny)]

    xminTop = [float('inf') for i_ in range(ny)]
    xmaxTop = [float('-inf') for i_ in range(ny)]
    
    xmin, xmax = float('inf'), float('-inf')
    for i in range(ny):
        yvalue = yvalues[i]
        xmin = min(xmin, ymap[yvalue][0][0])
        xmax = max(xmax, ymap[yvalue][-1][0])
        xminBottom[i] = xmin
        xmaxBottom[i] = xmax
        
    xmin, xmax = float('inf'), float('-inf')
    for i in range(ny)[::-1]:
        yvalue = yvalues[i]
        xmin = min(xmin, ymap[yvalue][0][0])
        xmax = max(xmax, ymap[yvalue][-1][0])
        xminTop[i] = xmin
        xmaxTop[i] = xmax

    ans = float('inf')
    
    for ptr in range(nx):
        leftArea = 0
        if (ptr > 0):
            ymin, ymax = yminLeft[ptr - 1], ymaxLeft[ptr - 1]
            leftArea = (ymax - ymin) * (xvalues[ptr - 1] - xvalues[0])

        ymin, ymax = yminRight[ptr], ymaxRight[ptr]
        rightArea = (ymax - ymin) * (xvalues[nx - 1] - xvalues[ptr])

        ans = min(ans, rightArea + leftArea)
    
    for ptr in range(ny):
        bottomArea = 0
        if (ptr > 0):
            xmin, xmax = xminBottom[ptr - 1], xmaxBottom[ptr - 1]
            bottomArea = (xmax - xmin) * (yvalues[ptr - 1] - yvalues[0])
        
        xmin, xmax = xminTop[ptr], xmaxTop[ptr]
        topArea = (xmax - xmin) * (yvalues[ny - 1] - yvalues[ptr])

        ans = min(ans, bottomArea + topArea)

    return ans


for _ in range(input()):
    n = input()
    points = []
    for v in range(n):
        points.append(map(int, raw_input().split()))
    print minimumDualArea(points, n)
