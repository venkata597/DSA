def fractional_knapsack(profits,weights,wlimit):
    n = len(p)
    x = [profits[i]/weights[i] for i in range(n)]
    
    for i in range(n-1):
        for j in range(i+1,n):
            if x[i] < x[j]:
                x[i],x[j] = x[j],x[i]
                profits[i],profits[j] = profits[j],profits[i]
                weights[i],weights[j] = weights[j],weights[i]
        
    total_pr = 0
    for i in range(n):
        if wlimit >= weights[i]:
            wlimit -= weights[i]
            total_pr += profits[i]
        else:
            total_pr += profits[i] * (wlimit/weights[i])
            break
    return total_pr


if __name__ == "__main__":
    # Sample Test Case
    p = [60,100,120]
    w = [10,20,30]
    capacity = 50
    print("Maximum Profit: ",fractional_knapsack(p,w,capacity))