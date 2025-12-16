N = 8;
n = 0:N-1;
levels = log2(N);

figure; hold on; axis off;
x = 1:levels+1;

for i = 1:N
    y = i;
    plot(x(1), y, 'ko');
    text(x(1)-0.1, y, sprintf('x(%d)', i-1));
end

for l = 1:levels
    step = 2^l;
    for i = 1:step:N
        for j = 0:step/2-1
            y1 = i + j;
            y2 = i + j + step/2;
            plot([x(l), x(l+1)], [y1, y1], 'b-');
            plot([x(l), x(l+1)], [y2, y1], 'r-');
        end
    end
end

title('FFT Butterfly Structure');
