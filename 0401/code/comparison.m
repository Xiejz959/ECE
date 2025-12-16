N = 256;
k = 6;

% Sparse spectrum
X_sparse = zeros(1,N);
idx = randperm(N,k);
X_sparse(idx) = randn(1,k);

% Dense spectrum
X_dense = randn(1,N);

figure;
subplot(2,1,1);
stem(abs(X_sparse), 'filled');
title('Sparse Frequency Spectrum');
xlabel('Frequency Index'); ylabel('Magnitude');

subplot(2,1,2);
stem(abs(X_dense), 'filled');
title('Dense Frequency Spectrum');
xlabel('Frequency Index'); ylabel('Magnitude');
