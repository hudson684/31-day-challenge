##
# CODEmas day 02
# Multi-Language Fibonacci Fun!
#
# Python 2.7 implementation
#

def FibSmallerThan(goal):
    # Find all Fibonacci numbers smaller than goal
    fibs = [0, 1]
    i = 1
    while fibs[i] < goal:
        fibs.append(fibs[i] + fibs[i-1])
        i += 1
    return fibs[1:-1]

def get_input():
    goal = -1
    while (goal < 0):
        goal = raw_input("Enter goal (0 to exit): ")
        try:
            goal = int(goal)
            if goal < 0:
                raise ValueError()
        except:
            goal = -1
            print "Invalid input!"
    return goal

def main():
    goal = get_input()
    while goal > 0:
        # Calculate Fibonacci numbers
        print FibSmallerThan(goal)
        # Get input
        goal = get_input()

if __name__ == "__main__":
    main()
