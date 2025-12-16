N = 256;
t = 0:N-1;

% Original sparse signal
freqs = [20, 60, 90];
x = zeros(1,N);
for f = freqs
    x = x + sin(2*pi*f*t/N);
end

% Subsample
M = 64;
idx = sort(randperm(N,M));
x_sub = x(idx);

% FFT
X = abs(fft(x));
X_sub = abs(fft(x_sub, M));

figure;
subplot(2,1,1);
stem(X);
title('Original Frequency Spectrum');
xlabel('Frequency Index'); ylabel('Magnitude');

subplot(2,1,2);
stem(X_sub);
title('Aliased Spectrum after Subsampling');
xlabel('Hashed Frequency Bin'); ylabel('Magnitude');
