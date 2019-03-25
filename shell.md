#常用shell命令
- cut
- awk
- sed
- sort
- uniq
- head 
- tail
- tr
- top
- ps
- find 
- which 
- whereis
- chmod
- chown
- chgrp
- cd 
- ls
- iptable
- crontab

#### example
- 给一行字符串，字符串是由很多端字符串组成的，求出该字符串中出现次数最短的短字符串iptables -I INPUT -p tcp --dport 8080 -j ACCEPT
    - input：iptables -I INPUT -p tcp --dport 8080 -j ACCEPT
    ```shelliptables -I INPUT -p tcp --dport 8080 -j ACCEPT
        str="heiptables -I INPUT -p tcp --dport 8080 -j ACCEPTllo world hello wo apple hiptables -I INPUT -p tcp --dport 8080 -j ACCEPTello hello appl world niptables -I INPUT -p tcp --dport 8080 -j ACCEPTokia unix" 
    ```
    - answer
    ```shell
        echo $str | sed 's/[ ]\+/\n/g' | sort | uniq -c | sort -rk 1 | head -n1 | awk '{print $2}'
    ```

-  给一个文件，文件中每一行是一个成绩，求总成绩，最高分，最低分以及平均分
    - input
    ```shell
        87
        89
        78
        23
        34
        54
        78
        45
    ```
    - answer
    ```shell
        cat ./test.in | awk 'BEGIN{sum=0;max=0;min=1000} {if(max<$1) max=$1;if(min>$1) min=$1;sum+=$1} END{print sum,min,max,sum/NR}'
    ```

- 杀死python相关进程
```shell
    ps -ef | grep python | awk '{print $2}' | xargs kill -9
```

- 查看端口占用
```shell
    lsof -i:port
    netstat -tunlp  | grep port
```

- 开启端口
```shell
    iptables -I INPUT -p tcp --dport 8080 -j ACCEPT
```


~~To be continue~~ 